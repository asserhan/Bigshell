/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:35:19 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/18 22:31:17 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	join_path(t_exec_context *ex_context)
{
	char	*tmp;
	int		i;

	i = -1;
	while (ex_context->cmd_paths[++i])
	{
		tmp = ex_context->cmd_paths[i];
		ex_context->cmd_paths[i] = ft_strjoin(tmp, "/");
		if (!ex_context->cmd_paths[i])
		{
			free_matrix(ex_context->cmd_paths);
			free(tmp);
			ft_msg_error("Error\n", 1);
		}
		free(tmp);
	}
}

void	ft_get_path(t_exec_context *ex_context)
{
	t_env_variable	*envp;

	ex_context->cmd_paths = NULL;
	envp = ex_context->env->first;
	while (envp)
	{
		ex_context->paths = search_env_elem(ex_context->env, "PATH");
		envp = envp->next;
	}
	if (!ex_context->paths)
		return ;
	ex_context->cmd_paths = ft_split(ex_context->paths->content, ':');
	if (!ex_context->cmd_paths)
	{
		free_matrix(ex_context->cmd_paths);
		ft_msg_error("Error\n", 1);
	}
	join_path(ex_context);
}

char	*ft_get_cmd_path(t_exec_context *ex_context)
{
	char	*my_cmd;
	int		i;

	i = -1;
	if (!ex_context->cmd_paths)
		return (ex_context->cmds->cmd);
	while (ex_context->cmd_paths[++i])
	{
		my_cmd = ft_strjoin(ex_context->cmd_paths[i], ex_context->cmds->cmd);
		if (access(my_cmd, F_OK | X_OK) == 0)
		{
			free(ex_context->cmds->cmd);
			return (my_cmd);
		}
		free(my_cmd);
	}
	return (NULL);
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
