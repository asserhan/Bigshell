#include "../../includes/minishell.h"

int	pars_input(t_exec_context *exContext, char *input)
{
	char **tokens;
	char **final_tokens;
	t_doubly_lst *cmd_list;

	if (input[0] != '\0')
		add_history(input);
	tokens = split_space(input);
	final_tokens = split_tokens(tokens, exContext);
	cmd_list = matrix_to_list(final_tokens);
	print_list(cmd_list);
	free(final_tokens);
	return (1);
}