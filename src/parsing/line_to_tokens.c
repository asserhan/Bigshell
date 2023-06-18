/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:40:17 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:40:18 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_line_to_tokens(int *i, char *delimiters, char *line_dup, char **tokens)
{
	int	s_quote;
	int	d_quote;

	s_quote = 0;
	d_quote = 0;
	i[1] = i[0];
	if (ft_strchr(delimiters, line_dup[i[0]]) == NULL)
	{
		while ((!ft_strchr(delimiters, line_dup[i[0]]) || s_quote || d_quote)
			&& line_dup[i[0]])
			handle_quotes(&s_quote, &d_quote, line_dup[i[0]++]);
	}
	else
		i[0]++;
	tokens[i[2]] = ft_substr(line_dup, i[1], i[0] - i[1]);
	if (!tokens[i[2]])
		return (free_matrix(tokens), 1);
	if (!ft_strcmp(tokens[i[2]], " "))
		free(tokens[i[2]]);
	else
		i[2]++;
	return (0);
}

void	line_to_tokens_delimiters(char *line, char *delimiters, char **tokens)
{
	int		i[3];
	char	*line_dup;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	line_dup = ft_strdup(line);
	while (line_dup && line_dup[i[0]] != '\0')
	{
		if (add_line_to_tokens(i, delimiters, line_dup, tokens))
			return ;
	}
	free(line_dup);
	tokens[i[2]] = NULL;
}
