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

static char	*subtoken(char *str, int i, t_exec_context *exContext)
{
	char	*var_value;
	char	*result;
	char	*sub;
	int		var_len;
	int		start;
	int		d_quote;

	start = i;
	var_value = NULL;
	if (str[i + 1] == '{')
	{
		var_len = find_char_index(&str[i + 1], "}") - 1;
		if (var_len >= 0)
		{
			sub = ft_substr(&str[i + 2], 0, var_len);
			var_value = get_env_value(sub, exContext);
			free(sub);
			i += var_len + 3;
		}
		else
			return (put_error("error : unclosed curly bracket ",
								NULL,
								2),
					NULL);
	}
	else if (str[i + 1] == '?')
	{
		var_value = ft_itoa(g_exit_status);
		i += 2;
	}
	else
	{
		var_len = find_char_index(&str[i + 1], "|\"' $.&-@:+=[]{}%~;#^*\\");
		if (var_len == -1)
			var_len = ft_strlen(&str[i + 1]);
		sub = ft_substr(&str[i + 1], 0, var_len);
		var_value = get_env_value(sub, exContext);
		free(sub);
		i += var_len + 1;
	}
	if (!var_value)
		var_value = ft_strdup("");
	d_quote = 0;
	while (str[start - 1 - d_quote] == '"' && str[i + d_quote] == '"')
		d_quote++;
	sub = ft_substr(str, 0, start - d_quote);
	result = ft_strjoin(sub, var_value);
	free(sub);
	free(var_value);
	sub = result;
	if (str[i] != '\0')
	{
		result = ft_strjoin(result, &str[i + d_quote]);
		free(sub);
	}
	return (result);
}

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
