/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_lstlast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:05:22 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/11 16:06:05 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_doubly_lst	*d_lstlast(t_doubly_lst *lst)
{
	t_doubly_lst	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
