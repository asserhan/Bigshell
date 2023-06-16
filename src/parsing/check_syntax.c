/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:48:18 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/11 15:48:57 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	delimiter_check(t_doubly_lst *head)
{
	if ((!head->next && !head->prev && ft_strlen(head->cmd) == 1
			&& ft_strchr("<|>)!", *head->cmd)) || (!head->next
			&& ft_strchr("<>()|", *head->cmd)) || (head->next && !head->prev
			&& ft_strlen(head->cmd) == 1 && ft_strchr("|", *head->cmd))
		|| (head->prev && head->next && ft_strchr("<>|", *head->cmd)
			&& ft_strchr("|", *head->next->cmd)))
	{
		put_error("syntax error near unexpected tdoken `", head->cmd, 258);
		return (1);
	}
	else
		return (0);
}

int	check_syntax(t_doubly_lst *head)
{
	while (head)
	{
		if (start_with(head->cmd, "!)") || end_with(head->cmd, "!)"))
		{
			put_error("syntax error near unexpected token `", "newline", 258);
			return (1);
		}
		if (end_with(head->cmd, "><!()") && head->next
			&& start_with(head->next->cmd, "|"))
			return (put_error("syntax error near unexpected token `", "|", 258),
					1);
		if (!head->have_quotes && delimiter_check(head))
			return (1);
		head = head->next;
	}
	return (0);
}
