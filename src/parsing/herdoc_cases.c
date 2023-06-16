#include "../../includes/minishell.h"

char	**heredoc_befor(char *token)
{
	char	**sub_tokens;
	int		count;

	count = words_number_delimiters(token,
									"<>| ");
	sub_tokens = malloc((count + 1) * sizeof(char *));
	if (!sub_tokens)
		return (NULL);
	line_to_tokens_delimiters(token, "<>| ", sub_tokens);
	return (sub_tokens);
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