#include "../../includes/minishell.h"

void	line_to_tokens_delimiters(char *line, char *delimiters, char **tokens)
{
	int		s_quote;
	int		d_quote;
	int		i[3];
	char	*line_dup;

	s_quote = 0;
	d_quote = 0;
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	line_dup = ft_strdup(line);
	while (line_dup && line_dup[i[0]] != '\0')
	{
		i[1] = i[0];
		if (ft_strchr(delimiters, line_dup[i[0]]) == NULL)
		{
			while ((!ft_strchr(delimiters, line_dup[i[0]]) || s_quote
					|| d_quote) && line_dup[i[0]])
				handle_quotes(&s_quote, &d_quote, line_dup[i[0]++]);
		}
		else
			i[0]++;
		tokens[i[2]] = ft_substr(line_dup, i[1], i[0] - i[1]);
		if (!tokens[i[2]])
			return (free_matrix(tokens));
		if (!ft_strcmp(tokens[i[2]], " "))
			free(tokens[i[2]]);
		else
			i[2]++;
	}
	free(line_dup);
	tokens[i[2]] = NULL;
}
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

char	**heredoc_in_token(char *token)
{
	char	**rtr;
	int		here_index;
	char	*befor;

	here_index = find_char_index(token, "<");
	if (here_index > 0 && !end_with(token, "<"))
	{
		befor = ft_substr(token, 0, here_index);
		rtr = ft_calloc(5, sizeof(char *));
		rtr[0] = ft_strdup(befor);
		rtr[1] = ft_strdup("<");
		rtr[2] = ft_strdup("<");
		rtr[3] = ft_strdup(ft_substr(token, here_index + 2, ft_strlen(token)));
		rtr[4] = NULL;
		free(befor);
	}
	else if (here_index > 0 && end_with(token, "<"))
	{
		befor = ft_substr(token, 0, here_index);
		rtr = ft_calloc(4, sizeof(char *));
		rtr[0] = ft_strdup(befor);
		rtr[1] = ft_strdup("<");
		rtr[2] = ft_strdup("<");
		rtr[3] = NULL;
		free(befor);
	}
	else if (here_index == 0 && !end_with(token, "<"))
	{
		rtr = ft_calloc(4, sizeof(char *));
		rtr[0] = ft_strdup("<");
		rtr[1] = ft_strdup("<");
		rtr[2] = ft_strdup(ft_substr(token, here_index + 2, ft_strlen(token)));
		rtr[3] = NULL;
	}
	else
	{
		rtr = ft_calloc(3, sizeof(char *));
		rtr[0] = ft_strdup("<");
		rtr[1] = ft_strdup("<");
		rtr[2] = NULL;
	}
	return (rtr);
}

char	**heredoc_befor(char *token)
{
	char	**rtr;

	rtr = ft_calloc(2, sizeof(char *));
	rtr[0] = ft_strdup(token);
	rtr[1] = NULL;
	return (rtr);
}

int	ends_with_heredoc(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	if (i > 1 && !ft_strcmp(matrix[i - 1], "<") && !ft_strcmp(matrix[i - 2],
			"<"))
	{
		return (1);
	}
	return (0);
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
		{
			sub_tokens = heredoc_befor(tokens[i++]);
		}
		else if (ft_strnstr(tokens[i], "<<", ft_strlen(tokens[i])))
		{
			sub_tokens = heredoc_in_token(tokens[i++]);
		}
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
