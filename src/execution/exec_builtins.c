/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:33:41 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/12 18:48:15 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "env") && ft_strcmp(cmd, "export") && ft_strcmp(cmd,
			"echo") && ft_strcmp(cmd, "unset") && ft_strcmp(cmd, "cd")
		&& ft_strcmp(cmd, "pwd") && ft_strcmp(cmd, "exit"))
		return (0);
	else
		return (1);
}

void	exec_builtins(t_exec_context *exContext)
{
	if (ft_strcmp(exContext->cmds->cmd, "env") == 0)
		ft_env(exContext);
	else if (ft_strcmp(exContext->cmds->cmd, "export") == 0)
		ft_export(exContext);
	else if (ft_strcmp(exContext->cmds->cmd, "echo") == 0)
		ft_echo(exContext->cmds->args);
	else if (ft_strcmp(exContext->cmds->cmd, "unset") == 0)
		ft_unset(exContext);
	else if (ft_strcmp(exContext->cmds->cmd, "cd") == 0)
		ft_cd(exContext->cmds->args, exContext->env);
	else if (ft_strcmp(exContext->cmds->cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(exContext->cmds->cmd, "exit") == 0)
		ft_exit(exContext->cmds->args);
}
