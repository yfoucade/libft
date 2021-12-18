/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:11:02 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:26:25 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		j;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		j = 0;
		while ((big[j] == little[j]) && little[j] && (j < len))
			j++;
		if (!little[j])
			return ((char *)big);
		if (!big[j])
			return (NULL);
		big++;
		len--;
	}
	return (NULL);
}
