/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:08:20 by yfoucade          #+#    #+#             */
/*   Updated: 2022/02/17 19:39:09 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char			*res;
	char			*tmp;
	char			chunk_buf[BUFFER_SIZE + 1];
	int				status;

	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '\0';
	status = READING;
	while (status == READING)
	{
		status = get_chunk(fd, chunk_buf);
		tmp = ft_strcat(res, chunk_buf);
		free(res);
		if (!tmp)
			return (NULL);
		res = tmp;
	}
	if ((res[0] == '\0') || status == ERROR)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

int	get_chunk(int fd, char *chunk_buf)
{
	static t_file_buffer	*files[MAX_FILES];
	int						idx;
	int						res;

	chunk_buf[0] = '\0';
	idx = (!fd) + (fd - 1) * (3 <= fd && fd <= 1025) - 1;
	if (idx < 0)
		return (ERROR);
	if (!files[idx])
	{
		files[idx] = (t_file_buffer *)malloc(sizeof(t_file_buffer));
		files[idx]->buf[0] = '\0';
		files[idx]->curr_index = 0;
	}
	res = fill_chunk(fd, chunk_buf, files[idx]);
	if (files[idx]->buf[0] == '\0')
	{
		free(files[idx]);
		files[idx] = NULL;
	}
	return (res);
}

int	fill_chunk(int fd, char *chunk_buf, t_file_buffer *file)
{
	int	ret;
	int	i;

	if (file->buf[file->curr_index] == '\0')
	{
		file->curr_index = 0;
		file->buf[0] = '\0';
		ret = read(fd, file->buf, BUFFER_SIZE);
		if (ret < 1)
			return (-2 * (ret == 0) - (ret < 0));
		file->buf[ret] = '\0';
	}
	ret = READING;
	i = 0;
	while (file->buf[file->curr_index] && file->buf[file->curr_index] != '\n')
		chunk_buf[i++] = file->buf[file->curr_index++];
	if (file->buf[file->curr_index] == '\n')
	{
		ret = EOL;
		chunk_buf[i++] = file->buf[file->curr_index++];
	}
	chunk_buf[i] = '\0';
	return (ret);
}
