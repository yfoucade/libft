/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:05:57 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:28:59 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*res;
	char	*cpy;

	size = ft_strlen(s);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	cpy = res;
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (res);
}
