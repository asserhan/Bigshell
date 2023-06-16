/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:58:32 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/15 16:31:10 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_dup(t_doubly_lst *commend)
{
	if (commend->in != STDIN_FILENO)
	{
		if (dup2(commend->in, STDIN_FILENO) == -1)
			ft_msg_error("dup2", 1);
	}
	if (commend->out != STDOUT_FILENO)
	{
		if (dup2(commend->out, STDOUT_FILENO) == -1)
			ft_msg_error("dup2", 1);
	}
}

void	ft_close_fd(t_exec_context *exContext)
{
	t_doubly_lst	*tmp;

	tmp = exContext->cmds;
	while (tmp)
	{
		if (tmp->in != STDIN_FILENO)
		{
			if (close(tmp->in) == -1)
				ft_msg_error("close", 1);
		}
		if (tmp->out != STDOUT_FILENO)
		{
			if (close(tmp->out) == -1)
				ft_msg_error("close", 1);
		}
		tmp = tmp->next;
	}
}
