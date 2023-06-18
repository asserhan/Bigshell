/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_lstadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:43:53 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:43:54 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	d_lstadd_back(t_doubly_lst **lst, t_doubly_lst *new)
{
	t_doubly_lst	*p;

	if (!lst || !new)
		return ;
	p = *lst;
	if (*lst)
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->prev = p;
	}
	else
		*lst = new;
}
