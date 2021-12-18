/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:08:27 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:25:18 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;

	if (n == 0)
		return (0);
	t1 = s1;
	t2 = s2;
	while (--n && (*t1 == *t2))
	{
		t1++;
		t2++;
	}
	return (*t1 - *t2);
}
