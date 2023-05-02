#include "../../includes/minishell.h"

void	expand_and_split_token(char *token, t_exec_context *exContext)
{
	char	*expanded_token;

	expanded_token = expand(token, exContext);
	(void)expanded_token;
}

char	**split_tokens(char **tokens, t_exec_context *exContext)
{
	// char **final_tokens;
	// char **sub_tokens;
	int command_count;
	int i;

	command_count = count_pointers(tokens);
	i = 0;
	while (i < command_count)
	{
		// Split the command by special characters and expand each part
		// sub_tokens = expand_and_split_token(tokens[i], exContext);
		expand_and_split_token(tokens[i++], exContext);
		// Add the modified command to the new array
		// ft_matrix_push_back(final_tokens, sub_tokens);

		// ft_free_matrix(&sub_tokens);
	}

	return (tokens);
}