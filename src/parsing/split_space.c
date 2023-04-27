#include "../../includes/minishell.h"
#include <stdbool.h>
#include <string.h>

int	words_number(const char *str, const char *delimiters)
{
	int		count;
	int		in_quotes;
	char	quote_char;

	count = 0;
	in_quotes = 0;
	quote_char = '\0';
	while (*str != '\0')
	{
		if (!ft_strchr(delimiters, *str))
		{
			count++;
			if (!in_quotes && (*str == '\"' || *str == '\''))
			{
				in_quotes = 1;
				quote_char = *str;
				str++;
			}
			else if (in_quotes && *str == quote_char)
				in_quotes = 0;
			while (*str != '\0' && (!ft_strchr(delimiters, *str) || in_quotes))
			{
				if (*str == quote_char)
					in_quotes = !in_quotes;
				str++;
			}
			if (in_quotes)
				return (-1);
		}
		str++;
	}
	return (count);
}

void	handle_quotes(int *s_quote, int *d_quote, char c)
{
	if (c == '\'' && *d_quote == 0)
		*s_quote = !*s_quote;
	else if (c == '\"' && *s_quote == 0)
		*d_quote = !*d_quote;
}

static char	**str_to_tokens(char const *str, char *delimiters, char **tokens)
{
	int		q[2];
	size_t	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	q[0] = 0;
	q[1] = 0;
	while (str[i[0]])
	{
		while (ft_strchr(delimiters, str[i[0]]) && str[i[0]] != '\0')
			i[0]++;
		i[1] = i[0];
		while ((!ft_strchr(delimiters, str[i[0]]) || q[0] || q[1]) && str[i[0]])
		{
			handle_quotes(&q[0], &q[1], str[i[0]]);
			i[0]++;
		}
		if (i[1] >= ft_strlen(str))
			tokens[i[2]++] = "\0";
		else
			tokens[i[2]++] = ft_substr(str, i[1], i[0] - i[1]);
	}
	return (tokens);
}

char	**split_space(char *line)
{
	char **tokens;
	int words = words_number(line, " ");

	if (!line)
		return (NULL);
	tokens = malloc((words + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	str_to_tokens(line, " ", tokens);
	tokens[words] = NULL;
	printf("this %s \n", tokens[0]);

	return (tokens);
}