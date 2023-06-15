/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/15 17:27:05 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	one_cmd(t_exec_context *exContext)
{
	ft_get_path(exContext);
	exContext->pid = fork();
	if (exContext->pid == -1)
		ft_msg_error("fork", 1);
	if (exContext->pid == 0)
	{
		if (exContext->cmds->next || exContext->cmds->cmd[0] != '\0')
			ft_dup(exContext->cmds);
		if (exContext->cmds->cmd[0] != '\0')
			ft_execute_child(exContext);
		else
		{
			if (exContext->cmds->in == 0 && exContext->cmds->out == 1)
			{
				put_error_ex("minishell: ", exContext->cmds->cmd,
					": command not found\n", 127);
			}
			exit(g_exit_status);
		}
	}
}

static int	mutiple_cmd(t_exec_context *exContext, int *k)
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

static void	exec_single(t_exec_context *exContext)
{
	int	fdout;
	int	fdin;

	if (is_builtin(exContext->cmds->cmd))
	{
		fdout = dup(1);
		fdin = dup(0);
		ft_dup(exContext->cmds);
		exec_builtins(exContext);
		dup2(fdout, 1);
		dup2(fdin, 0);
	}
	else
	{
		one_cmd(exContext);
		wait(NULL);
		free_matrix(exContext->cmd_paths);
	}
}

static void	ft_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

void	execution(t_exec_context *exContext)
{
	int				size;
	t_exec_context	*tmp;
	t_doubly_lst	*cmds;
	int				k;
	int				pid;

	k = 0;
	tmp = exContext;
	cmds = tmp->cmds;
	ft_signals();
	size = d_lstsize(exContext->cmds);
	exContext->pipe_num = size - 1;
	if (size == 1)
		exec_single(exContext);
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
}
