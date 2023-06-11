/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:35:43 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/11 09:48:00 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_execute_child(t_exec_context *exContext)
{
	if (exContext->cmds->cmd[0] == '\0')
	{
		if (exContext->cmds->in == 0 && exContext->cmds->out == 1)
		{
			put_error_ex("minishell: ", exContext->cmds->cmd,
					": command not found\n", 127);
		}
		ft_close_fd(exContext);
		return ;
	}
	if (exContext->paths && ft_strchr(exContext->cmds->cmd, '/') == NULL)
	{
		exContext->cmds->cmd = ft_get_cmd_path(exContext);
		free_matrix(exContext->cmd_paths);
	}
	else
		free_matrix(exContext->cmd_paths);
	if (!exContext->cmds->cmd)
	{
		put_error_ex("minishell: ", exContext->cmds->cmd, "command not found\n",
				127);
		free(exContext->cmds->cmd);
		exit(127);
	}
	execve(exContext->cmds->cmd, exContext->cmds->args,
			exContext->env->env_array);
	ft_msg_error("execve", 127);
	exit(127);
}

void	ft_child_process(t_exec_context *exContext, int *k, int *end)
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