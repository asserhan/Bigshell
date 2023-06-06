#include "../../includes/minishell.h"

char	*expand_token(char *token, t_exec_context *exContext)
{
	char	*var_result;
	char	*result;
	char	*path;

	var_result = var_expand(token, exContext);
	path = get_env_value("HOME", exContext);
	if (!var_result || !path)
		return (NULL);
	result = path_expand(var_result, path);
	free(path);
	return (result);
}
void	line_to_tokens_delimiters(char const *line, char *delimiters,
		char **tokens)
{
	int	s_quote;
	int	d_quote;
	int	i[3];

	s_quote = 0;
	d_quote = 0;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (line && line[i[0]] != '\0')
	{
		i[1] = i[0];
		if (ft_strchr(delimiters, line[i[0]]) == NULL)
		{
			while ((!ft_strchr(delimiters, line[i[0]]) || s_quote || d_quote)
				&& line[i[0]])
			{
				handle_quotes(&s_quote, &d_quote, line[i[0]]);
				i[0]++;
			}
		}
		else
			i[0]++;
		tokens[i[2]] = ft_substr(line, i[1], i[0] - i[1]);
		if (!tokens[i[2]++])
			return (free_matrix(tokens));
	}
	tokens[i[2]] = NULL;
}
int	words_number_delimiters(const char *str, const char *delimiters)
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
			{
				handle_quotes(&s_quote, &d_quote, str[i++]);
			}
			if (s_quote || d_quote)
				return (-1);
		}
		else
			i++;
	}
	return (count);
}
char	**split_tokens(char **tokens, t_exec_context *exContext)
{
	char	**final_tokens;
	char	**sub_tokens;
	char	*line_expended;
	int		command_count;
	int		i;

	command_count = count_matrix(tokens);
	i = 0;
	final_tokens = NULL;
	while (i < command_count)
	{
		line_expended = expand_token(tokens[i++], exContext);
		if (!line_expended)
			return (NULL);
		sub_tokens = ft_calloc((words_number_delimiters(line_expended, "<>|")
					+ 1), sizeof(char *));
		if (!sub_tokens)
			return (NULL);
		line_to_tokens_delimiters(line_expended, "<>|", sub_tokens);
		final_tokens = matrix_concat(final_tokens, sub_tokens);
		free_matrix(sub_tokens);
	}
	return (final_tokens);
}
