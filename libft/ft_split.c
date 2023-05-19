/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:39:05 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/25 16:51:36 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_words(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	next_word(const char *s, size_t *begin, size_t *end, char c)
{
	while (s[*begin] == c)
			(*begin)++;
		*end = *begin;
	while (s[*end] && s[*end] != c)
			(*end)++;
}

static char	**free_strings(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i++]);
	}
	free (str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	begin;
	size_t	end;
	size_t	i;

	if (s == NULL)
		return (NULL);
	strings = (char **) malloc((nbr_words(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	begin = 0;
	end = 0;
	i = 0;
	while (i < nbr_words(s, c))
	{
		next_word(s, &begin, &end, c);
		strings[i] = ft_substr(s, begin, (end - begin));
		if (!strings[i])
			return (free_strings(strings));
		i++;
		begin = end;
	}
	strings[i] = NULL;
	return (strings);
}
