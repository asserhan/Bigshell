#include "../../includes/minishell.h"

int check_syntax(t_doubly_lst *head)
{
	while (head)
	{
		if (start_with(head->cmd, "!)") || end_with(head->cmd, "!)"))
			return (ft_printf("bash: syntax error near unexpected token `%c'\n", head->cmd[0]) && 1);
		if (end_with(head->cmd, "><!()") && head->next && start_with(head->next->cmd, "|"))
			return (ft_printf("bash: syntax error near unexpected token `|'\n") && 1);
		if ((!head->next && !head->prev && ft_strlen(head->cmd) == 1 && ft_strchr("<|>)!", *head->cmd)) || (!head->next && ft_strchr("<>()|", *head->cmd)) || (head->next && !head->prev && ft_strlen(head->cmd) == 1 && ft_strchr("|", *head->cmd)) || (head->prev && head->next && ft_strchr("<>|", *head->cmd) && ft_strchr("|", *head->next->cmd)))
			return (ft_printf("bash: syntax error near unexpected token `%s'\n", head->cmd) && 1);
		head = head->next;
	}
	return (0);
}
t_doubly_lst *convert_list_format(t_doubly_lst *list)
{

	t_doubly_lst *node;
	t_doubly_lst *head = NULL;
	t_doubly_lst *prev_node = NULL;

	while (list)
	{
		if (ft_strcmp(list->cmd, "|") && (!list->prev || (list->prev && !ft_strcmp(list->prev->cmd, "|"))))
		{

			node = d_lstnew(list->cmd);
			if (!head)
				head = node;
			if (prev_node)
			{
				prev_node->next = node;
				node->prev = prev_node;
			}
			prev_node = node;
			if (find_char_index(list->cmd, "<>") < 0)
				list = list->next;
		}

		while (list && ft_strcmp(list->cmd, "|") && node)
		{
			if (!ft_strcmp(list->cmd, ">") && !ft_strcmp(list->next->cmd, ">"))
			{
				handle_append(list, node);
				list = list->next->next->next;
				continue;
			}
			else if (!ft_strcmp(list->cmd, ">"))
			{
				handle_output(list, node);
				list = list->next->next;
				continue;
			}
			else if (!ft_strcmp(list->cmd, "<"))
			{
				handle_input(list, node);
				list = list->next->next;
				continue;
			}
			node->args = matrix_push_back(node->args, list->cmd);
			list = list->next;
		}
		if (list && !ft_strcmp(list->cmd, "|"))
			list = list->next;
	}
	return head;
}

int pars_input(t_exec_context *exContext, char *input)
{
	char **tokens;
	char **final_tokens;
	t_doubly_lst *cmd_list;
	t_doubly_lst *final_list;

	if (input[0] != '\0')
		add_history(input);
	tokens = split_space(input);
	if (!tokens)
		return 1;
	final_tokens = split_tokens(tokens, exContext);
	free_matrix(&tokens);
	cmd_list = matrix_to_list(final_tokens);
	free_matrix(&final_tokens);
	if (check_syntax(cmd_list))
		return (1);
	final_list = convert_list_format(cmd_list);
	print_list(final_list);
	return (0);
}