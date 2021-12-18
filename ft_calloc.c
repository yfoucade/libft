/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:52:07 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:44:29 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	max_size_t(void)
{
	int		i;
	int		nbits;
	size_t	res;

	i = -1;
	nbits = 8 * sizeof(size_t);
	res = 0;
	while (++i < nbits)
		res = (res << 1) + 1;
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb * size == 0)
		return (malloc(0));
	if (nmemb > max_size_t() / size)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	res = ft_memset(res, '\0', nmemb * size);
	return (res);
}
