/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:35:19 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/09 18:32:20 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	join_path(t_exec_context *exContext)
{
	char	*tmp;
	int		i;

	i = -1;
	while (exContext->cmd_paths[++i])
	{
		tmp = exContext->cmd_paths[i];
		exContext->cmd_paths[i] = ft_strjoin(tmp, "/");
		if (!exContext->cmd_paths[i])
		{
			free_matrix(exContext->cmd_paths);
			free(tmp);
			ft_msg_error("Error\n", 1);
		}
		free(tmp);
	}
}

void	ft_get_path(t_exec_context *exContext)
{
	t_env_variable	*envp;

	exContext->cmd_paths = NULL;
	envp = exContext->env->first;
	while (envp)
	{
		exContext->paths = search_env_elem(exContext->env, "PATH");
		envp = envp->next;
	}
	if (!exContext->paths)
		return ;
	exContext->cmd_paths = ft_split(exContext->paths->content, ':');
	if (!exContext->cmd_paths)
	{
		free_matrix(exContext->cmd_paths);
		ft_msg_error("Error\n", 1);
	}
	join_path(exContext);
}

char	*ft_get_cmd_path(t_exec_context *exContext)
{
	char	*my_cmd;
	int		i;

	i = -1;
	if (!exContext->cmd_paths)
		return (exContext->cmds->cmd);
	while (exContext->cmd_paths[++i])
	{
		my_cmd = ft_strjoin(exContext->cmd_paths[i], exContext->cmds->cmd);
		if (access(my_cmd, F_OK | X_OK) == 0)
		{
			free(exContext->cmds->cmd);
			return (my_cmd);
		}
		free(my_cmd);
	}
	return (NULL);
}
