/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:17:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/22 19:33:14 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void print_list(t_doubly_lst *head)
{
	while (head)
	{
		ft_printf("--------------------------\n");
		ft_printf("cmd : |%s| \n",head->cmd);
		ft_printf("agrs :  ");
		print_matrix(head->args,' ');
		ft_printf("\n");
		ft_printf("in : |%d|\n",head->in);
		ft_printf("out : |%d|\n",head->out);
		ft_printf("--------------------------\n");

		head = head->next;
	}
}
