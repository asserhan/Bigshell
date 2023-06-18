/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/18 19:28:34 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	one_cmd(t_exec_context *ex_context)
{
	ft_get_path(ex_context);
	ex_context->pid = fork();
	if (ex_context->pid == -1)
		ft_msg_error("fork", 1);
	if (ex_context->pid == 0)
	{
		ft_signals();
		if (ex_context->cmds->next || ex_context->cmds->cmd[0] != '\0')
			ft_dup(ex_context->cmds);
		if (ex_context->cmds->cmd[0] != '\0')
			ft_execute_child(ex_context);
		else
		{
			if (ex_context->cmds->in == 0 && ex_context->cmds->out == 1
				&& ex_context->cmds->is_heredoc == 0)
			{
				put_error_ex("minishell: ", ex_context->cmds->cmd,
					": command not found\n", 127);
			}
			exit(g_exit_status);
		}
	}
}

static int	mutiple_cmd(t_exec_context *ex_context, int *k)
{
	int	end[2];
	int	pid;

	if (pipe(end) == -1)
		ft_msg_error("pipe", 1);
	pid = fork();
	if (pid == -1)
	{
		ft_msg_error("fork", 1);
	}
	if (pid == 0)
	{
		ft_signals();
		ft_child_process(ex_context, k, end);
	}
	else
	{
		if (*k)
			close(*k);
		*k = dup(end[0]);
		close(end[1]);
		close(end[0]);
	}
	add_fd(ex_context, *k);
	return (pid);
}

void	update_underscore(t_exec_context *ex_context)
{
	if (!(ex_context->cmds->next))
	{
		update_env_elem(ex_context->env, "_",
			last_element_matrix(ex_context->cmds->args));
		free_matrix(ex_context->env->env_array);
		ex_context->env->env_array = env_to_matrix(ex_context->env->first);
	}
}

void	ft_wait(int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			ft_putstr_fd("\n", 1);
		if (WTERMSIG(status) == 3)
			ft_putstr_fd("Quit: 3\n", 1);
		g_exit_status = 128 + WTERMSIG(status);
	}
}

static void	exec_single(t_exec_context *ex_context)
{
	int	fdout;
	int	fdin;

	update_underscore(ex_context);
	if (is_builtin(ex_context->cmds->cmd))
	{
		fdout = dup(1);
		fdin = dup(0);
		ft_dup(ex_context->cmds);
		exec_builtins(ex_context);
		dup2(fdout, 1);
		dup2(fdin, 0);
	}
	else
	{
		one_cmd(ex_context);
		ft_wait(ex_context->pid);
		free_matrix(ex_context->cmd_paths);
	}
}

void	ft_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
}

void	ft_ign_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	execution(t_exec_context *ex_context)
{
	int				size;
	t_exec_context	*tmp;
	int				k;
	int				pid;

	k = 0;
	tmp = ex_context;
	ft_ign_signals();
	size = d_lstsize(ex_context->cmds);
	ex_context->pipe_num = size - 1;
	if (size == 1)
		exec_single(ex_context);
	else
	{
		while (tmp->cmds)
		{
			update_underscore(ex_context);
			pid = mutiple_cmd(tmp, &k);
			tmp->cmds = tmp->cmds->next;
		}
		ft_wait(pid);
		while (wait(NULL) != -1)
			;
	}
}
