/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/09 18:36:24 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"




void	one_cmd(t_exec_context *exContext)
{
	ft_get_path(exContext);
	exContext->pid = fork();
	if (exContext->pid == -1)
		ft_msg_error("fork", 1);
	if (exContext->pid == 0)
	{
		ft_dup(exContext);
		ft_execute_child(exContext);
	}
}
int	mutiple_cmd(t_exec_context *exContext, int *k)
{
	int	end[2];
	int	pid;

	if (pipe(end) == -1)
		ft_msg_error("pipe", 1);
	pid = fork();
	if (pid == -1)
		ft_msg_error("fork", 1);
	if (pid == 0)
	{
		
		if (!exContext->cmds->next)
			dup2(*k, 0);
		else
		{
			if (dup2(end[1], STDOUT_FILENO) == -1)
				ft_msg_error("dup2", 1);
			if (dup2(*k, STDIN_FILENO) == -1)
				ft_msg_error("dup2", 1);
		}
		close(end[0]);
		close(end[1]);
		if (is_builtin(exContext->cmds->cmd))
		{
			ft_dup(exContext);
			exec_builtins(exContext);
			exit(0);
		}
		else
		{
			ft_get_path(exContext);
			ft_dup(exContext);
			ft_execute_child(exContext);
		}
	}
	else
	{
		if (*k)
			close(*k);
		*k = dup(end[0]);
		close(end[1]);
		close(end[0]);
	}
	return (pid);
}

void	execution(t_exec_context *exContext)
{
	int				size;
	
	t_exec_context	*tmp;
	int				k;
	int				fdout;
	int				fdin;
	int pid;

	k = 0;
	tmp = exContext;
	
	size = d_lstsize(exContext->cmds);
	exContext->pipe_num = size - 1;
	if (size == 1)
	{
		if (is_builtin(exContext->cmds->cmd))
		{
			fdout = dup(1);
			fdin = dup(0);
			ft_dup(exContext);
			exec_builtins(exContext);
			dup2(fdout, 1);
			dup2(fdin, 0);
		}
		else
		{
			one_cmd(exContext);
			wait(NULL);
		}
	}
	else
	{
		while (tmp->cmds)
		{
			pid = mutiple_cmd(tmp, &k);
			tmp->cmds = tmp->cmds->next;
		}
		waitpid(pid, NULL, 0);
		while (wait(NULL) != -1)
			;
	}
	ft_close_fd(exContext);
}
