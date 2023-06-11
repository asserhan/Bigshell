/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:58:32 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/11 13:56:01 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_dup(t_exec_context *exContext)
{
	if (exContext->cmds->in != STDIN_FILENO)
	{
		if (dup2(exContext->cmds->in, STDIN_FILENO) == -1)
			ft_msg_error("dup2", 1);
	}
	if (exContext->cmds->out != STDOUT_FILENO)
	{
		if (dup2(exContext->cmds->out, STDOUT_FILENO) == -1)
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
void	ft_dup_built(t_exec_context *exContext)
{
	int fd_out;
	int fd_in;
	fd_out = dup(STDOUT_FILENO);
	fd_in = dup(STDIN_FILENO);
	ft_dup(exContext);
	exec_builtins(exContext);
	dup2(fd_out, STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
}