/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_lstclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:44:04 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:44:05 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	d_lstclear(t_doubly_lst **lst)
{
	t_doubly_lst	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->args)
			free_matrix((*lst)->args);
		if ((*lst)->cmd)
		{
			if ((*lst)->cmd)
			{
				free((*lst)->cmd);
				(*lst)->cmd = NULL;
			}
		}
		temp = *lst;
		*lst = temp->next;
		if (temp)
			free(temp);
	}
	*lst = NULL;
}
