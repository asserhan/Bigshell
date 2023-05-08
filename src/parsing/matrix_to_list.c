/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:02:54 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/08 15:31:15 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_doubly_lst	*matrix_to_list(char **matrix)
{
	t_doubly_lst	*head;
	t_doubly_lst	*tail;
    t_doubly_lst	*node;
	char *cmd;

	head = NULL;
	tail = NULL;
	while (*matrix)
	{
		cmd = ft_strtrim(*matrix++,"'\"");
		if (cmd && *cmd)
		{
			node = (t_doubly_lst *)malloc(sizeof(t_doubly_lst));
			if(!node)
				return (NULL);
			node->prev = tail;
			node->next = NULL;
			node->cmd = cmd;
			if (tail)
				tail->next = node;
			tail = node;
			if (!head)
				head = node;
		}
	}
	return (head);
}
