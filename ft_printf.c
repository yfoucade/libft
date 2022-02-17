/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:48:00 by yfoucade          #+#    #+#             */
/*   Updated: 2022/02/17 20:01:06 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	unsigned int	res;
	va_list			ap;

	res = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			res += write(1, fmt, 1);
		else if (*++fmt == '%')
			res += write(1, "%%", 1);
		else if (*fmt == 'c' || *fmt == 's' || *fmt == 'p')
			res += ft_putcsp(*fmt, ap);
		else if (*fmt == 'd' || *fmt == 'i')
			res += ft_putdec(va_arg(ap, int));
		else if (*fmt == 'u')
			res += ft_putnbrbase(va_arg(ap, unsigned), 10, 0);
		else if (*fmt == 'x' || *fmt == 'X')
			res += ft_putnbrbase(va_arg(ap, unsigned), 16, *fmt == 'x');
		fmt++;
	}
	va_end(ap);
	return (res);
}
