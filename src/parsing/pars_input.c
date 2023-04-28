#include "../../includes/minishell.h"

int	pars_input(t_exec_context *exContext, char *input)
{
	char **tokens;
	char **final_tokens;

	if (input[0] != '\0')
		add_history(input);
	tokens = split_space(input);
	final_tokens = split_tokens(tokens, exContext);
	free(final_tokens);
	return (1);
}