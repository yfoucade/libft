/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:41:00 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:32:50 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_chars(unsigned int n)
{
	size_t	res;

	res = 1;
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static char	*return_int_min(void)
{
	char	*res;

	res = malloc(12);
	if (!res)
		return (NULL);
	ft_strlcpy(res, "-2147483648\0", 12);
	return (res);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*res;
	size_t	n_chars;

	if (n == -2147483648)
		return (return_int_min());
	sign = n;
	n *= 1 - 2 * (n < 0);
	n_chars = count_chars(n) + (sign < 0);
	res = malloc(n_chars + 1);
	if (!res)
		return (NULL);
	res[n_chars] = '\0';
	while (n_chars)
	{
		res[--n_chars] = '0' + n % 10;
		n /= 10;
	}
	if (sign < 0)
		res[0] = '-';
	return (res);
}
