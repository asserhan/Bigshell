/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:35:43 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/08 15:52:17 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_execute_child(t_exec_context *exContext)
{
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