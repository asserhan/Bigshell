/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:17 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/24 13:00:58 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count + 1);
}

static char	*word_by_word(char *s, char c, size_t *start)
{
	int		i;
	int		end;
	char	*rtr;

	i = *start;
	while (s[i] && s[i] == c)
		i++;
	*start = i;
	while (s[i] && s[i] != c)
		i++;
	end = i;
	rtr = ft_substr(s, *start, end - *start);
	if (rtr == NULL)
		free(rtr);
	*start = end;
	return (rtr);
}

static int	protection(char const *s, char **trim, char ***rtr, char c)
{
	if (!s)
		return (0);
	*trim = ft_strtrim(s, &c);
	if (!(*trim))
		return (0);
	*rtr = (char **)malloc((word_count(*trim, c) + 1) * sizeof(char *));
	if (!(*rtr))
	{
		free(*trim);
		return (0);
	}
	return (1);
}

static void	ft_free_all(char **rtn)
{
	size_t	i;

	i = 0;
	while (rtn[i])
	{
		free(rtn[i]);
		i++;
	}
	free(rtn);
	rtn = 0;
}

char	**ft_split(char const *s, char c)
{
	char	*trim;
	char	**rtr;
	int		i;
	size_t	start;

	i = 0;
	start = 0;
	if (!(protection(s, &trim, &rtr, c)))
		return (NULL);
	while (start < ft_strlen(trim))
	{
		*(rtr + i) = word_by_word(trim, c, &start);
		if (*(rtr + i) == NULL)
		{
			ft_free_all(rtr);
			return (NULL);
		}
		i++;
	}
	*(rtr + i) = 0;
	free(trim);
	return (rtr);
}
