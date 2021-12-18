/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:06:09 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:10:25 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i <= start)
		if (s[i] == '\0')
			return (ft_calloc(1, 1));
	s += start;
	size = 0;
	while (s[size] && size < len)
		size++;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size)
		res[i] = s[i];
	res[len] = '\0';
	return (res);
}
