/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_lstnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:17:47 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/04 16:17:50 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_doubly_lst	*d_lstnew(char *cmd)
{
	t_doubly_lst	*rtr;

	rtr = malloc(sizeof(t_doubly_lst));
	if (!rtr)
		return (NULL);
	rtr->cmd = ft_strdup(cmd);
	rtr->next = NULL;
	rtr->prev = NULL;
	return (rtr);
}
