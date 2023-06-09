/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:34:45 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/09 10:06:20 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int		g_exit_status;

t_doubly_lst	*create_node_after_heredeoc(t_doubly_lst *list)
{
	t_doubly_lst	*node;

	node = NULL;
	if (list->prev && list->prev->prev && !ft_strcmp(list->prev->cmd, "<")
		&& !ft_strcmp(list->prev->prev->cmd, "<"))
		node = d_lstnew(list->cmd);
	else
		node = d_lstnew(remove_quotes(list->cmd));
	return (node);
}

t_doubly_lst	*remove_quotes_from_list(t_doubly_lst *list)
{
	t_doubly_lst	*head;
	t_doubly_lst	*node;
	t_doubly_lst	*prev_node;

	head = NULL;
	prev_node = NULL;
	while (list)
	{
		node = create_node_after_heredeoc(list);
		if (ft_strchr(list->cmd, '\'') || ft_strchr(list->cmd, '\"'))
			node->have_quotes = 1;
		if (!head)
			head = node;
		if (prev_node)
		{
			prev_node->next = node;
			node->prev = prev_node;
		}
		prev_node = node;
		list = list->next;
	}
	return (head);
}

void	add_cmd_to_args(t_doubly_lst *final_list)
{
	while ((final_list))
	{
		(final_list)->args = matrix_add_front((final_list)->cmd,
												(final_list)->args);
		(final_list) = (final_list)->next;
	}
}
int	pars_input(t_exec_context *exContext, char *input)
{
	char			**tokens;
	char			**final_tokens;
	t_doubly_lst	*cmd_list;
	t_doubly_lst	*list_without_quotes;
	t_doubly_lst	*final_list;

	tokens = split_space(input);
	free(input);
	if (!tokens)
		return (1);
	final_tokens = split_tokens(tokens, exContext);
	free_matrix(tokens);
	if (!final_tokens)
		return (1);
	cmd_list = matrix_to_list(final_tokens);
	free_matrix(final_tokens);
	list_without_quotes = remove_quotes_from_list(cmd_list);
	d_lstclear(&cmd_list);
	if (check_syntax(list_without_quotes))
		return (1);
	final_list = convert_list_format(list_without_quotes, exContext);
	if (!final_list)
		return (1);
	add_cmd_to_args(final_list);
	// print_list(final_list);
	exContext->cmds = final_list;
	d_lstclear(&list_without_quotes);
	return (0);
}
