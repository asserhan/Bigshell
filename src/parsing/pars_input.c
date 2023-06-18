/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:34:45 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/17 19:17:32 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int		g_exit_status;

t_doubly_lst	*create_node_after_heredeoc(t_doubly_lst *list)
{
	t_doubly_lst	*node;
	char			*no_quotes;

	node = NULL;
	if (list->prev && list->prev->prev && !ft_strcmp(list->prev->cmd, "<")
		&& !ft_strcmp(list->prev->prev->cmd, "<"))
		node = d_lstnew(list->cmd);
	else
	{
		no_quotes = remove_quotes(list->cmd);
		node = d_lstnew(no_quotes);
		free(no_quotes);
	}
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
	t_doubly_lst	*tmp;

	tmp = final_list;
	while ((tmp))
	{
		(tmp)->args = matrix_add_front((tmp)->cmd,
				(tmp)->args);
		(tmp) = (tmp)->next;
	}
}

int	pars_input(t_exec_context *ex_context, char *input)
{
	char			**tokens;
	char			**final_tokens;
	t_doubly_lst	*cmd_list;
	t_doubly_lst	*list_without_quotes;
	t_doubly_lst	*final_list;

	tokens = split_space(input);
	if (!tokens)
		return (1);
	final_tokens = split_tokens(tokens, ex_context);
	free_matrix(tokens);
	if (!final_tokens)
		return (1);
	cmd_list = matrix_to_list(final_tokens);
	free_matrix(final_tokens);
	list_without_quotes = remove_quotes_from_list(cmd_list);
	d_lstclear(&cmd_list);
	if (check_syntax(list_without_quotes))
		return (d_lstclear(&list_without_quotes), 1);
	final_list = convert_list_format(list_without_quotes, ex_context);
	if (!final_list)
		return (d_lstclear(&list_without_quotes), 1);
	add_cmd_to_args(final_list);
	ex_context->cmds = final_list;
	return (d_lstclear(&list_without_quotes), 0);
}
