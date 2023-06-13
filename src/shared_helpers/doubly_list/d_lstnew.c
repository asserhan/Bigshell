/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_lstnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:17:47 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/13 13:44:35 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_doubly_lst	*d_lstnew(char *cmd)
{
	t_doubly_lst	*rtr;

	rtr = ft_calloc(1, sizeof(t_doubly_lst));
	if (!rtr)
		return (NULL);
	rtr->cmd = ft_strdup(cmd);
	rtr->args = NULL;
	rtr->have_quotes = 0;
	rtr->in = 0;
	rtr->out = 1;
	rtr->next = NULL;
	rtr->prev = NULL;
	return (rtr);
}
