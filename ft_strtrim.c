/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:35:40 by yfoucade          #+#    #+#             */
/*   Updated: 2021/11/26 15:10:15 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (is_in_set(*s1, set) && *s1)
		s1++;
	end = 0;
	i = -1;
	while (s1[++i])
		if (!is_in_set(s1[i], set))
			end = i;
	res = ft_substr(s1, 0, end + 1);
	return (res);
}
