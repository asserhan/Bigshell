/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:47:06 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/11 19:31:54 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*expand(char *token, int i, t_exec_context *exContext)
{
	char	*new_token;

	new_token = subtoken(token, i, exContext);
	if (!new_token)
		return (NULL);
	free(token);
	token = NULL;
	return (var_expand(new_token, exContext));
}

char	*var_expand(char *token, t_exec_context *exContext)
{
	int	s_quote;
	int	d_quote;
	int	i;
	int	should_expand;

	s_quote = 0;
	d_quote = 0;
	i = -1;
	while (token[++i])
	{
		handle_quotes(&s_quote, &d_quote, token[i]);
		if (!s_quote && token[i] == '$' && token[i + 1])
		{
			should_expand = 1;
			if (i == 0 || token[i - 1] != '\\')
			{
				if (ft_strchr("/~%^}:; ", token[i + 1])
					|| (find_char_index("\"", &token[i + 1]) < 0 && d_quote))
					should_expand = 0;
			}
			if (should_expand)
				return (expand(token, i, exContext));
		}
	}
	return (token);
}

char	*expand_token(char *token, t_exec_context *exContext)
{
	char	*result;
	char	*path;
	char	*expand;
	char	*token_dup;

	token_dup = ft_strdup(token);
	expand = var_expand(token_dup, exContext);
	path = get_env_value("HOME", exContext);
	result = path_expand(expand, path);
	free(path);
	if (result != expand)
		free(expand);
	return (result);
}
