/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:35:43 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/18 19:40:09 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_directory(t_exec_context *ex_context)
{
	struct stat	file_stat;

	if (ft_strchr(ex_context->cmds->cmd, '/') && access(ex_context->cmds->cmd,
			X_OK) != -1)
	{
		stat(ex_context->cmds->cmd, &file_stat);
		if (S_ISDIR(file_stat.st_mode))
		{
			(put_error_ex("minishell: ", ex_context->cmds->cmd,
					": is a directory\n", 126));
			d_lstdelone(&(ex_context->cmds), ex_context->cmds);
			return (1);
		}
		else if (access(ex_context->cmds->cmd, F_OK) == -1)
		{
			(put_error_ex("minishell: ", ex_context->cmds->cmd,
					": No such file or directory\n", 127));
			d_lstdelone(&(ex_context->cmds), ex_context->cmds);
			return (1);
		}
	}
	return (0);
}

void	ft_execute_child(t_exec_context *ex_context)
{
	if (is_directory(ex_context))
		exit(g_exit_status);
	if (ex_context->paths && ft_strchr(ex_context->cmds->cmd, '/') == NULL)
	{
		ex_context->cmds->cmd = ft_get_cmd_path(ex_context);
		free_matrix(ex_context->cmd_paths);
	}
	else
		free_matrix(ex_context->cmd_paths);
	if (!ex_context->cmds->cmd)
	{
		put_error_ex("minishell: ", ex_context->cmds->cmd,
			"command not found\n", 127);
		free(ex_context->cmds->cmd);
		exit(127);
	}
	execve(ex_context->cmds->cmd, ex_context->cmds->args,
		ex_context->env->env_array);
	ft_msg_error("minishell", 127);
	exit(g_exit_status);
}

static void	ft_run(t_exec_context *ex_context)
{
	ft_get_path(ex_context);
	ft_dup(ex_context->cmds);
	ft_execute_child(ex_context);
}

void	ft_empty_cmd(t_exec_context *ex_context)
{
	if (ex_context->cmds->in == 0 && ex_context->cmds->out == 1
		&& ex_context->cmds->is_heredoc == 0)
	{
		put_error_ex("minishell: ", ex_context->cmds->cmd,
			": command not found\n", 127);
	}
}

void	ft_child_process(t_exec_context *ex_context, int *k, int *end)
{
	dup_pipe(ex_context, k, end);
	if (ex_context->cmds->cmd[0] != '\0')
	{
		if (is_builtin(ex_context->cmds->cmd))
		{
			ft_dup(ex_context->cmds);
			exec_builtins(ex_context);
			exit(0);
		}
		else
			ft_run(ex_context);
	}
	else
	{
		ft_empty_cmd(ex_context);
		exit(g_exit_status);
	}
}
