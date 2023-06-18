/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:43:09 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:43:11 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	words_number_delimiters(char *str, char *delimiters)
{
	int	s_quote;
	int	d_quote;
	int	i;
	int	count;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	count = 0;
	while (str && str[i] != '\0')
	{
		count++;
		if (!ft_strchr(delimiters, str[i]))
		{
			while ((s_quote || d_quote || !ft_strchr(delimiters, str[i]))
				&& str[i])
				handle_quotes(&s_quote, &d_quote, str[i++]);
			if (s_quote || d_quote)
				return (-1);
		}
		else
			i++;
	}
	return (count);
}

int	split_with_del(char ***final_tokens, char **tokens,
		t_exec_context *ex_context, int *i)
{
	char	**sub_tokens;
	char	*line_expended;
	int		count;

	if (*final_tokens && ends_with_heredoc(*final_tokens))
		sub_tokens = heredoc_befor(tokens[*i]);
	else
	{
		line_expended = expand_token(tokens[*i], ex_context);
		if (!line_expended)
			return (1);
		count = words_number_delimiters(line_expended, "<>| ");
		sub_tokens = malloc((count + 1) * sizeof(char *));
		if (!sub_tokens)
			return (1);
		line_to_tokens_delimiters(line_expended, "<>| ", sub_tokens);
		free(line_expended);
	}
	*final_tokens = matrix_concat(*final_tokens, sub_tokens);
	free_matrix(sub_tokens);
	return (0);
}

char	**split_tokens(char **tokens, t_exec_context *ex_context)
{
	char	**final_tokens;
	int		command_count;
	int		i;

	command_count = count_matrix(tokens);
	i = 0;
	final_tokens = NULL;
	while (i < command_count)
	{
		if (split_with_del(&final_tokens, tokens, ex_context, &i))
			return (NULL);
		i++;
	}
	return (final_tokens);
}
