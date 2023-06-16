#include "../../includes/minishell.h"

int	betwen_bracets(int *i, char *str, t_exec_context *exContext,
		char **var_value)
{
	int		var_len;
	char	*sub;

	var_len = find_char_index(&str[*i + 1], "}") - 1;
	if (var_len >= 0)
	{
		sub = ft_substr(&str[*i + 2], 0, var_len);
		*var_value = get_env_value(sub, exContext);
		free(sub);
		*i += var_len + 3;
	}
	else
		return (put_error("error : unclosed curly bracket ", NULL, 2), 1);
	return (0);
}

void	default_case(int *i, char *str, t_exec_context *exContext,
		char **var_value)
{
	int		var_len;
	char	*sub;

	var_len = find_char_index(&str[*i + 1],
								"|\"' $.&-@:+=[]{}%~;#^*\\1234567890");
	if (var_len == -1)
		var_len = ft_strlen(&str[*i + 1]);
	sub = ft_substr(&str[*i + 1], 0, var_len);
	*var_value = get_env_value(sub, exContext);
	free(sub);
	*i += var_len + 1;
}

void	join_expand_to_str(int *i, int start, char *str, char **var_value,
		char **result)
{
	int		d_quote;
	char	*sub;

	if (!*var_value)
		*var_value = ft_strdup("");
	d_quote = 0;
	while (str[start - 1 - d_quote] == '"' && str[*i + d_quote] == '"')
		d_quote++;
	sub = ft_substr(str, 0, start - d_quote);
	*result = ft_strjoin(sub, *var_value);
	free(sub);
	free(*var_value);
	sub = *result;
	if (str[*i] != '\0')
	{
		*result = ft_strjoin(*result, &str[*i + d_quote]);
		free(sub);
	}
}

char	*subtoken(char *str, int i, t_exec_context *exContext)
{
	char *var_value;
	char *result;
	int start;

	start = i;
	var_value = NULL;
	if (str[i + 1] == '{')
	{
		if (betwen_bracets(&i, str, exContext, &var_value) == 1)
			return (NULL);
	}
	else if (str[i + 1] == '?')
	{
		var_value = ft_itoa(g_exit_status);
		i += 2;
	}
	else
		default_case(&i, str, exContext, &var_value);
	join_expand_to_str(&i, start, str, &var_value, &result);
	return (result);
}