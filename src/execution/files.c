/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:58:32 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/18 19:38:40 by hasserao         ###   ########.fr       */
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

void	ft_close_fd(t_exec_context *ex_context)
{
	t_list	*tmp;

	tmp = ex_context->fds;
	while (tmp)
	{
		close(((int *)tmp->content)[0]);
		tmp = tmp->next;
	}
	ft_lstclear(&(ex_context->fds), free);
}

void	dup_pipe(t_exec_context *ex_context, int *k, int *end)
{
	if (!ex_context->cmds->next)
		dup2(*k, STDIN_FILENO);
	else
	{
		if (dup2(end[1], STDOUT_FILENO) == -1)
			ft_msg_error("dup2", 1);
		if (dup2(*k, STDIN_FILENO) == -1)
			ft_msg_error("dup2", 1);
	}
	close(end[0]);
	close(end[1]);
}
