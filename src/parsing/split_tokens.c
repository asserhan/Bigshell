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

char	**split_tokens(char **tokens, t_exec_context *exContext)
{
	char	**final_tokens;
	char	**sub_tokens;
	char	*line_expended;
	int		command_count;
	int		i;
	int		count;

	command_count = count_matrix(tokens);
	i = 0;
	final_tokens = NULL;
	while (i < command_count)
	{
		if (final_tokens && ends_with_heredoc(final_tokens))
			sub_tokens = heredoc_befor(tokens[i++]);
		else
		{
			line_expended = expand_token(tokens[i++], exContext);
			if (!line_expended)
				return (NULL);
			count = words_number_delimiters(line_expended,
											"<>| ");
			sub_tokens = malloc((count + 1) * sizeof(char *));
			if (!sub_tokens)
				return (NULL);
			line_to_tokens_delimiters(line_expended, "<>| ", sub_tokens);
			free(line_expended);
		}
		final_tokens = matrix_concat(final_tokens, sub_tokens);
		free_matrix(sub_tokens);
	}
	return (final_tokens);
}
