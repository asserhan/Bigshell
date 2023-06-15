/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/13 15:05:16 by otait-ta         ###   ########.fr       */
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
		if (exContext->cmds->next || exContext->cmds->cmd[0] != '\0')
			ft_dup(exContext->cmds);
		if (exContext->cmds->cmd[0] != '\0')
			ft_execute_child(exContext);
		else
			exit(g_exit_status);
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

void	update_underScore(t_exec_context *exContext)
{
	if (!(exContext->cmds->next))
	{
		update_env_elem(exContext->env, "_",
				last_element_matrix(exContext->cmds->args));
		free_matrix(exContext->env->env_array);
		exContext->env->env_array = env_to_matrix(exContext->env->first);
	}
}

void	execution(t_exec_context *exContext)
{
	int				size;
	t_exec_context	*tmp;
	int				k;
	int				fdout;
	int				fdin;
	int				pid;

	k = 0;
	tmp = exContext;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	size = d_lstsize(exContext->cmds);
	exContext->pipe_num = size - 1;
	if (size == 1)
	{
		update_underScore(exContext);
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
	else
	{
		// cmd_tmp = exContext->cmds;
		while (tmp->cmds)
		{
			update_underScore(exContext);
			pid = mutiple_cmd(tmp, &k);
			tmp->cmds = tmp->cmds->next;
		}
		waitpid(pid, NULL, 0);
		while (wait(NULL) != -1)
			;
	}
	ft_close_fd(exContext);
}
