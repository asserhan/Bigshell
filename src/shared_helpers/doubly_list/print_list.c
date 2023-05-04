/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:17:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/04 16:17:55 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void print_list(t_doubly_lst *head)
{
	while (head)
	{
		ft_putstr_fd(head->cmd, 1);
		ft_putchar_fd('\n', 1);
		head = head->next;
	}
}