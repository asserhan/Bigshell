/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:35:19 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/03 23:42:47 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_get_path(t_exec_context *exContext)
{
	char			*tmp;
	t_env_variable	*envp;
	int				i;

	exContext->cmd_paths = NULL;
	envp = exContext->env->first;
	i = -1;
	while (envp)
	{
		exContext->paths = search_env_elem(exContext->env, "PATH");
		envp = envp->next;
	}
	if (!exContext->paths)
		return ;
	exContext->cmd_paths = ft_split(exContext->paths->content, ':');
	if (!exContext->cmd_paths)
		ft_msg_error("Error\n", 1);
	while (exContext->cmd_paths[++i])
	{
		tmp = exContext->cmd_paths[i];
		exContext->cmd_paths[i] = ft_strjoin(tmp, "/");
		if (!exContext->cmd_paths[i])
			ft_msg_error("Error\n", 1);
		free(tmp);
	}
}
char	*ft_get_cmd_path(t_exec_context *exContext)
{
	char *my_cmd;
	int i;
	i = -1;
	if (!exContext->cmd_paths)
		return (exContext->cmds->cmd); // update
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