/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:04:56 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:24:51 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*t;

	t = s;
	if (n == 0)
		return (NULL);
	while (--n && (*t != c))
		t++;
	if (*t == c)
		return ((char *)t);
	return (NULL);
}
