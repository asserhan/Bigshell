/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:58:32 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/11 15:30:10 by otait-ta         ###   ########.fr       */
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
	t_list	*tmp;

	tmp = exContext->fds;
	while (tmp)
	{
		close(((int *)tmp->content)[0]);
		tmp = tmp->next;
	}
	ft_lstclear(&(exContext->fds), free);
}
// void	ft_dup_built(t_exec_context *exContext)
// {
// 	int fd_out;
// 	int fd_in;
// 	fd_out = dup(STDOUT_FILENO);
// 	fd_in = dup(STDIN_FILENO);
// 	ft_dup(exContext);
// 	exec_builtins(exContext);
// 	dup2(fd_out, STDOUT_FILENO);
// 	dup2(fd_in, STDIN_FILENO);
// }