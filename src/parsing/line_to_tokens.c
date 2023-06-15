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
