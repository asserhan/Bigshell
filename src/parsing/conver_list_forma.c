/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_list_forma.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:43:12 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/13 15:51:14 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int		g_exit_status;

int	redirection_type(t_doubly_lst *list)
{
	if (!ft_strcmp(list->cmd, ">") && !ft_strcmp(list->next->cmd, ">")
		&& !list->have_quotes)
		return (APPEND);
	else if (!ft_strcmp(list->cmd, "<") && !ft_strcmp(list->next->cmd, "<")
			&& !list->have_quotes)
		return (HERE_DOC);
	else if (!ft_strcmp(list->cmd, ">") && !list->have_quotes)
		return (OUT);
	else if (!ft_strcmp(list->cmd, "<") && !list->have_quotes)
		return (IN);
	return (-1);
}

int	fill_in_out(t_doubly_lst **list, t_doubly_lst **node,
		t_exec_context *exContext, int *red_type)
{
	*red_type = redirection_type((*list));
	if (*red_type == APPEND)
		handle_append((*list), *node);
	else if (*red_type == HERE_DOC)
		handle_heredoc((*list), *node, exContext);
	else if (*red_type == OUT)
		handle_output((*list), *node);
	else if (*red_type == IN)
		handle_input((*list), *node);
	if (g_exit_status != 0)
		return (1);
	if (*red_type == APPEND || *red_type == HERE_DOC)
		(*list) = (*list)->next->next->next;
	else
		(*list) = (*list)->next->next;
	return (0);
}
void	create_node(t_doubly_lst **node, t_doubly_lst **head,
		t_doubly_lst **list)
{
	if (ft_strcmp((*list)->cmd, "|") && (!(*list)->prev || ((*list)->prev
				&& !ft_strcmp((*list)->prev->cmd, "|"))))
	{
		if (find_char_index((*list)->cmd, "><") >= 0)
			(*node) = d_lstnew("");
		else
			(*node) = d_lstnew((*list)->cmd);
		d_lstadd_back(head, (*node));
		if (find_char_index((*list)->cmd, "<>") < 0)
			(*list) = (*list)->next;
	}
}

t_doubly_lst	*convert_list_format(t_doubly_lst *list,
									t_exec_context *exContext)
{
	t_doubly_lst	*node;
	t_doubly_lst	*head;
	int				red_type;
	char			**args;

	head = NULL;
	node = NULL;
	args = NULL;
	while (list)
	{
		create_node(&node, &head, &list);
		while (list && ft_strcmp(list->cmd, "|") && node)
		{
			if (find_char_index(list->cmd, "><") >= 0)
			{
				if (fill_in_out(&list, &node, exContext, &red_type))
				{
					d_lstclear(&head);
					return (NULL);
				}
				// if (red_type == HERE_DOC && ((list && ft_strchr(list->cmd,
				// '|')
				// 			&& node->cmd[0] == '\0') || !(list)))
				// 	d_lstdelone(&head, node);
				continue ;
			}
			if (node->cmd[0] == '\0')
			{
				free(node->cmd);
				node->cmd = ft_strdup(list->cmd);
			}
			else
			{
				args = matrix_push_back(node->args, list->cmd);
				free(node->args);
				node->args = args;
			}
			list = list->next;
		}
		if (list && !ft_strcmp(list->cmd, "|"))
			list = list->next;
	}
	return (head);
}
