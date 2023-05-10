#include "../../includes/minishell.h"

int check_syntax(t_doubly_lst *head)
{
	while (head)
	{
		if (start_with(head->cmd, "!)") || end_with(head->cmd, "!)"))
			return (ft_printf("bash: syntax error near unexpected token `%c'\n", head->cmd[0]) && 1);
		if (end_with(head->cmd, "><!()") && head->next && start_with(head->next->cmd, "|"))
			return (ft_printf("bash: syntax error near unexpected token `|'\n") && 1);
		if ((!head->next && !head->prev && ft_strlen(head->cmd) == 1 && ft_strchr("<|>)!", *head->cmd))
			|| (!head->next && ft_strchr("<>()|", *head->cmd))
			|| (head->next && !head->prev && ft_strlen(head->cmd) == 1 && ft_strchr("|", *head->cmd))
			|| (head->prev && head->next && ft_strchr("<>|", *head->cmd) && ft_strchr("|", *head->next->cmd)))
			return (ft_printf("bash: syntax error near unexpected token `%s'\n", head->cmd) && 1);
		head = head->next;
	}
	return (0);
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
	if (check_syntax(cmd_list))
		return (1);
	print_list(cmd_list);
	free_matrix(&final_tokens);
	return (0);
}