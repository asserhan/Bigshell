#include "../../includes/minishell.h"

char	**here_in_middel(char *token, int here_index)
{
	char	*befor;
	char	**rtr;

	befor = ft_substr(token, 0, here_index);
	rtr = ft_calloc(5, sizeof(char *));
	rtr[0] = ft_strdup(befor);
	rtr[1] = ft_strdup("<");
	rtr[2] = ft_strdup("<");
	rtr[3] = ft_strdup(ft_substr(token, here_index + 2, ft_strlen(token)));
	rtr[4] = NULL;
	free(befor);
	return (rtr);
}
char	**here_at_end(char *token, int here_index)
{
	char	*befor;
	char	**rtr;

	befor = ft_substr(token, 0, here_index);
	rtr = ft_calloc(4, sizeof(char *));
	rtr[0] = ft_strdup(befor);
	rtr[1] = ft_strdup("<");
	rtr[2] = ft_strdup("<");
	rtr[3] = NULL;
	free(befor);
	return (rtr);
}
char	**heredoc_in_token(char *token)
{
	char	**rtr;
	int		here_index;

	here_index = find_char_index(token, "<");
	if (here_index > 0 && !end_with(token, "<"))
		rtr = here_in_middel(token, here_index);
	else if (here_index > 0 && end_with(token, "<"))
		rtr = here_at_end(token, here_index);
	else if (here_index == 0 && !end_with(token, "<"))
	{
		rtr = ft_calloc(4, sizeof(char *));
		rtr[0] = ft_strdup("<");
		rtr[1] = ft_strdup("<");
		rtr[2] = ft_substr(token, here_index + 2, ft_strlen(token));
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
