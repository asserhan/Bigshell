/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/03 22:22:53 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <string.h>

void	exec_builtins(t_exec_context *exContext)
{
	// pid_t	pid;
	// char	*str[4];
	// str[4] = {"ls", "-l", NULL};
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
	// pid=fork();
	// if (pid == 0)
	// 	execve("/bin/ls", str, NULL);
	// else
	// 	wait(NULL);
	// //execve("/bin/ls", str, NULL);
}
int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "env") && ft_strcmp(cmd, "export") && ft_strcmp(cmd,
			"echo") && ft_strcmp(cmd, "unset") && ft_strcmp(cmd, "cd")
		&& ft_strcmp(cmd, "pwd") && ft_strcmp(cmd, "exit"))
		return (0);
	else
		return (1);
}
void	one_cmd(t_exec_context *exContext)
{
	ft_get_path(exContext);
	exContext->pid = fork();
	if (exContext->pid == -1)
		ft_msg_error("fork", 1);
	if (exContext->pid == 0)
	{
		ft_dup(exContext);
		ft_execute_child(exContext);
	}
}
void	execution(t_exec_context *exContext)
{
	int			size;
	struct stat	fileStat;

	if (exContext->cmds->cmd[0] == '\0')
		// todo close the fds
		return ;
	stat(exContext->cmds->cmd, &fileStat);
	if (S_ISDIR(fileStat.st_mode))
		return (put_error_ex("minishell: ", exContext->cmds->cmd,
				": is a directory\n", 126));
	size = d_lstsize(exContext->cmds);
	if (size == 1 && is_builtin(exContext->cmds->cmd))
		exec_builtins(exContext);
	else if (size == 1 && !is_builtin(exContext->cmds->cmd))
	{
		one_cmd(exContext);
		// wait(NULL);
	}
}
