/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfoucade <yfoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:53:15 by yfoucade          #+#    #+#             */
/*   Updated: 2021/12/17 17:29:53 by yfoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	char	out;
	size_t	res;

	res = 0;
	out = 1;
	while (*s)
	{
		if (*s == c)
			out = 1;
		else if (out)
		{
			out = 0;
			res++;
		}
		s++;
	}
	return (res);
}

static void	free_n_first_words(char **tab, size_t n)
{
	while (n--)
		free(*tab++);
}

static char	copy_words(char **dest, char const *s, char c, size_t word_count)
{
	size_t		curr_word;
	const char	*end;

	curr_word = -1;
	while (++curr_word < word_count)
	{
		while (*s == c)
			s++;
		end = s + 1;
		while (*end && *end != c)
			end++;
		dest[curr_word] = ft_substr(s, 0, end - s);
		if (!dest[curr_word])
		{
			free_n_first_words(dest, curr_word);
			return (1);
		}
		s = end;
	}
	dest[curr_word] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**res;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	if (copy_words(res, s, c, word_count))
	{
		free(res);
		return (NULL);
	}
	return (res);
}
