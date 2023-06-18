/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:43:16 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:43:17 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	betwen_bracets(int *i, char *str, t_exec_context *ex_context,
		char **var_value)
{
	int		var_len;
	char	*sub;

	var_len = find_char_index(&str[*i + 1], "}") - 1;
	if (var_len >= 0)
	{
		sub = ft_substr(&str[*i + 2], 0, var_len);
		*var_value = get_env_value(sub, ex_context);
		free(sub);
		*i += var_len + 3;
	}
	else
		return (put_error("error : unclosed curly bracket ", NULL, 2), 1);
	return (0);
}

void	default_case(int *i, char *str, t_exec_context *ex_context,
		char **var_value)
{
	int		var_len;
	char	*sub;
	int		start;

	start = *i;
	var_len = *i;
	while (ft_isalpha(str[*i + 1]) || str[*i + 1] == '_')
		(*i)++;
	var_len = *i - var_len;
	if (var_len == -1)
		var_len = ft_strlen(&str[start + 1]);
	sub = ft_substr(&str[start + 1], 0, var_len);
	*var_value = get_env_value(sub, ex_context);
	free(sub);
	*i += 1;
}

char	*join_expand_to_str(int *i, int start, char *str, char **var_value)
{
	int		d_quote;
	char	*sub;
	char	*result;

	if (!*var_value)
		*var_value = ft_strdup("");
	d_quote = 0;
	while (str[start - 1 - d_quote] == '"' && str[*i + d_quote] == '"')
		d_quote++;
	sub = ft_substr(str, 0, start - d_quote);
	result = ft_strjoin(sub, *var_value);
	free(sub);
	free(*var_value);
	sub = result;
	if (str[*i] != '\0')
	{
		result = ft_strjoin(result, &str[*i + d_quote]);
		free(sub);
	}
	return (result);
}

char	*subtoken(char *str, int i, t_exec_context *ex_context)
{
	char	*var_value;
	char	*result;
	int		start;

	start = i;
	var_value = NULL;
	if (str[i + 1] == '{')
	{
		if (betwen_bracets(&i, str, ex_context, &var_value) == 1)
			return (NULL);
	}
	else if (str[i + 1] == '?')
	{
		var_value = ft_itoa(g_exit_status);
		i += 2;
	}
	else
		default_case(&i, str, ex_context, &var_value);
	result = join_expand_to_str(&i, start, str, &var_value);
	return (result);
}
