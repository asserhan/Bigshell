#include "../../includes/minishell.h"

int check_syntax(t_doubly_lst *head)
{
	while (head)
	{
		if (!head->next && !head->prev)
		{
			if (ft_strlen(head->cmd) == 1 && ft_strchr("<|>)!", *head->cmd))
				ft_printf("bash: syntax error near unexpected token `%s'\n", head->cmd);
		}
		else if (!head->next)
			if (ft_strchr("<>()", *head->cmd))
				ft_printf("bash: syntax error near unexpected token `newline'\n", head->cmd);
		head = head->next;
	}
	return 1;
}
int pars_input(t_exec_context *exContext, char *input)
{
	char **tokens;
	char **final_tokens;
	t_doubly_lst *cmd_list;

	if (input[0] != '\0')
		add_history(input);
	tokens = split_space(input);
	if (!tokens)
		return 1;
	final_tokens = split_tokens(tokens, exContext);
	cmd_list = matrix_to_list(final_tokens);
	check_syntax(cmd_list);
	// print_list(cmd_list);
	free_matrix(&final_tokens);
	return (1);
}