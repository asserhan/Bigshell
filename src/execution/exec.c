/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/09 21:48:41 by otait-ta         ###   ########.fr       */
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
		ft_child_process(exContext, k, end);
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
	t_doubly_lst	*tmp2;
	int				k;
	int				fdout;
	int				fdin;
	int				pid;
	struct stat		fileStat;

	k = 0;
	tmp = exContext;
	tmp2 = tmp->cmds;
	while (tmp2 && ft_strchr(tmp2->cmd, '/'))
	{
		stat(tmp2->cmd, &fileStat);
		if (S_ISDIR(fileStat.st_mode))
			return (put_error_ex("minishell: ", tmp2->cmd, ": is a directory\n",
					126));
		tmp2 = tmp2->next;
	}
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
