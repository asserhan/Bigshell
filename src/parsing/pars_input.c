#include "../../includes/minishell.h"

int	pars_input(t_exec_context *exContext, char *input)
{
	(void)exContext;
	if (input[0] != '\0')
		add_history(input);
	split_space(input);
	return (1);
}