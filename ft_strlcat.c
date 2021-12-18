/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:45:35 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 14:25:23 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = -1;
	while ((++i < size) && *dst)
		dst++;
	while (i + 1 < size && *src)
	{
		i++;
		*dst++ = *src++;
	}
	if (i < size)
		*dst = '\0';
	while (*src++)
		i++;
	return (i);
}
