#include "../../includes/minishell.h"

int check_syntax(t_doubly_lst *head)
{
	while (head)
	{
		if (start_with(head->cmd, "!)"))
		{
			ft_printf("bash: syntax error near unexpected token `%c'\n", head->cmd[0]);
			return (1);
		}
		else if (end_with(head->cmd, "!)"))
		{
			ft_printf("bash: syntax error near unexpected token `)'\n");
			return (1);
		}
		else if (end_with(head->cmd, "><!()") && head->next &&start_with(head->next->cmd, "|"))
		{
			ft_printf("bash: syntax error near unexpected token `|'\n");
			return (1);
		}
		else if (!head->next && !head->prev)
		{
			if (ft_strlen(head->cmd) == 1 && ft_strchr("<|>)!", *head->cmd))
			{
				ft_printf("bash: syntax error near unexpected token `%s'\n", head->cmd);
				return (1);
			}
		}
		else if (!head->next)
		{
			if (ft_strchr("<>()|", *head->cmd))
			{
				ft_printf("bash: syntax error near unexpected token `newline'\n");
				return (1);
			}
		}
		else if (head->next && !head->prev)
		{
			if (ft_strlen(head->cmd) == 1 && ft_strchr("|", *head->cmd))
			{
				ft_printf("bash: syntax error near unexpected token `%s'\n", head->cmd);
				return (1);
			}
		}
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