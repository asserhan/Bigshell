/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:33:41 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/11 15:29:08 by otait-ta         ###   ########.fr       */
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

void	exec_builtins(t_exec_context *exContext, t_doubly_lst *commend)
{
	if (ft_strcmp(commend->cmd, "env") == 0)
		ft_env(exContext, commend);
	else if (ft_strcmp(commend->cmd, "export") == 0)
		ft_export(exContext, commend);
	else if (ft_strcmp(commend->cmd, "echo") == 0)
		ft_echo(commend->args);
	else if (ft_strcmp(commend->cmd, "unset") == 0)
		ft_unset(exContext, commend);
	else if (ft_strcmp(commend->cmd, "cd") == 0)
		ft_cd(commend->args, exContext->env);
	else if (ft_strcmp(commend->cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(commend->cmd, "exit") == 0)
		ft_exit(commend->args);
}
