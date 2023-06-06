/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/06 17:22:03 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <string.h>

void	exec_builtins(t_exec_context *exContext)
{
	// pid_t	pid;
	// char	*str[4];
	// str[4] = {"ls", "-l", NULL};
	//ft_dup(exContext);
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
	//ft_close_fd(exContext);
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
int	mutiple_cmd(t_exec_context *exContext, int *w)
{
	int	end[2];
	int	pid;
	// static int w;
	
	if (pipe(end) == -1)
		ft_msg_error("pipe", 1);
	pid = fork();
	if (pid == -1)
		ft_msg_error("fork", 1);
	if (pid == 0)
	{
		// if (dup2(end[1], STDOUT_FILENO) == -1)
		// 	ft_msg_error("dup2", 1);
		if(!exContext->cmds->next)
			dup2(*w, 0);
		else
		{
			if (dup2(end[1], STDOUT_FILENO) == -1)
				ft_msg_error("dup2", 1);
			if (dup2(*w, STDIN_FILENO) == -1)
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
	else
	{
		if (*w)
			close(*w);
		*w = dup(end[0]);
		close(end[1]);
		close(end[0]);
	}
	return (pid);
}
void	pipes_end(t_exec_context *exContext)
{
	int	i;

	i = 0;
	while (exContext->cmds)
	{
		if (i == 0 && exContext->cmds->next)
		{
			if (exContext->cmds->out == 1)
				exContext->cmds->out = exContext->pipe_fd[i][1];
		}
		else if (i != 0 && exContext->cmds->next)
		{
			if (exContext->cmds->out == 1)
				exContext->cmds->out = exContext->pipe_fd[i][1];
			if (exContext->cmds->in == 0)
				exContext->cmds->in = exContext->pipe_fd[i - 1][0];
		}
		else if (i != 0 && !exContext->cmds->next)
		{
			if (exContext->cmds->in == 0)
				exContext->cmds->in = exContext->pipe_fd[i - 1][0];
		}
		i++;
		exContext->cmds = exContext->cmds->next;
	}
}
int	create_pipes(t_exec_context *exContext, int size)
{
	int	i;
	exContext->pipe_fd = NULL;

	i = 0;
	if (size > 1)
	{
		exContext->pipe_fd = malloc(sizeof(int *) * exContext->pipe_num);
		if (!exContext->pipe_fd)
			ft_msg_error("malloc", 1);
		while (i < exContext->pipe_num)
		{
			exContext->pipe_fd[i] = malloc(sizeof(int) * 2);
			if (!exContext->pipe_fd[i])
				ft_msg_error("malloc", 1);
			if (pipe(exContext->pipe_fd[i]) == -1)
				ft_msg_error("pipe", 1);
			i++;
		}
		pipes_end(exContext);
	}
	return (0);
}
void	execution(t_exec_context *exContext)
{
	int			size;
	struct stat	fileStat;
	//int			pid;
	t_exec_context *tmp;
	int w;

	w = 0;
	// int i;
	// i=-1 it me;
	tmp = exContext;

	if (exContext->cmds->cmd[0] == '\0')
		// todo close the fds
		return ;
 
	stat(exContext->cmds->cmd, &fileStat);
	if (S_ISDIR(fileStat.st_mode))
		return (put_error_ex("minishell: ", exContext->cmds->cmd,
				": is a directory\n", 126));
	size = d_lstsize(exContext->cmds);
	exContext->pipe_num = size - 1;
	if (size == 1)
	{
		if (is_builtin(exContext->cmds->cmd))
		{
			int fdout = dup(1);
			int fdin = dup(0);
			ft_dup(exContext);
			exec_builtins(exContext);
			dup2(fdout, 1);
			dup2(fdin, 0);
			//exit(0);
		}
		else
		{
			one_cmd(exContext);
			wait(NULL);
		}
	}
	else
	{
	
		int pid;
		while(tmp->cmds)
		{
			//ft_printf(" hiiti\n");
			pid = mutiple_cmd(tmp, &w);
			tmp->cmds = tmp->cmds->next;
		}
		waitpid(pid, NULL, 0);
		while (wait(NULL) != -1);
		
	}
}
