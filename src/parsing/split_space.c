/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:43:01 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:43:02 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_words(char **str, const char *delimiters, char *quote_char,
		int *in_quotes)
{
	if (!*in_quotes && (**str == '\"' || **str == '\''))
	{
		*in_quotes = 1;
		*quote_char = **str;
		*str = *str + 1;
	}
	else if (*in_quotes && (**str == *quote_char))
		*in_quotes = 0;
	while (**str != '\0' && (!ft_strchr(delimiters, **str) || *in_quotes))
	{
		if (**str == *quote_char)
			*in_quotes = !*in_quotes;
		else if ((**str == '\'' || **str == '\"') && !*in_quotes)
		{
			*in_quotes = 1;
			*quote_char = **str;
		}
		*str = *str + 1;
	}
	if (*in_quotes)
		return (-1);
	return (0);
}

int	words_number(const char *str, const char *delimiters)
{
	int		count;
	char	quote_char;
	int		in_quotes;

	count = 0;
	quote_char = '\0';
	in_quotes = 0;
	while (*str != '\0')
	{
		if (!ft_strchr(delimiters, *str))
		{
			count++;
			if (count_words((char **)&str, delimiters, &quote_char,
					&in_quotes) == -1)
				return (-1);
		}
		if (*str)
			str++;
	}
	return (count);
}

void	handle_quotes(int *s_quote, int *d_quote, char c)
{
	if (c == '\'' && *d_quote == 0)
		*s_quote = !*s_quote;
	else if (c == '\"' && *s_quote == 0)
		*d_quote = !*d_quote;
}

void	line_to_tokens(char const *line, char *delimiters, char **tokens)
{
	int		q[2];
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	q[0] = 0;
	q[1] = 0;
	while (line[i[0]])
	{
		while (ft_strchr(delimiters, line[i[0]]) && line[i[0]] != '\0')
			i[0]++;
		i[1] = i[0];
		while ((!ft_strchr(delimiters, line[i[0]]) || q[0] || q[1])
			&& line[i[0]])
		{
			handle_quotes(&q[0], &q[1], line[i[0]]);
			i[0]++;
		}
		if (i[1] >= ft_strlen(line))
			tokens[i[2]++] = NULL;
		else
			tokens[i[2]++] = ft_substr(line, i[1], i[0] - i[1]);
	}
}

char	**split_space(char *line)
{
	char	**tokens;
	int		words;

	words = words_number(line, " ");
	if (words < 0)
		return (put_error("minishell: error while searching for a "
				"corresponding quotation mark. `", NULL, 2), NULL);
	tokens = malloc((words + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	line_to_tokens(line, " ", tokens);
	tokens[words] = NULL;
	if (!tokens)
		free_matrix(tokens);
	return (tokens);
}
