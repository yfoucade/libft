/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:54:17 by yfoucade          #+#    #+#             */
/*   Updated: 2022/02/17 20:07:21 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	printf_ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	printf_ft_putstr(char *s)
{
	unsigned int	res;

	if (s == NULL)
		return (write(1, "(null)", 6));
	res = ft_strlen(s);
	write(1, s, res);
	return (res);
}
