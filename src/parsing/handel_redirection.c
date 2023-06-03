/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:01:03 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/03 22:17:31 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	exit_status;

char	*get_dir(char *path)
{
	char	*dir;
	int		i;

	if (!path || !*path)
		return (NULL);
	i = ft_strlen(path);
	while (path[i] != '/')
		i--;
	dir = ft_substr(path, 0, i);
	return (dir);
}

void	handle_input(t_doubly_lst *old_list, t_doubly_lst *node)
{
	int		fd;
	char	*path;

	path = old_list->next->cmd;
	if (access(path, F_OK) == -1)
		put_error("minishell: No such file or directory: ", path, 1);
	else if (access(path, R_OK) == -1 && access(path, F_OK) == 0)
		put_error("minishell: permission denied: ", path, 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("minishell: No such file or directory ", 2);
	node->in = fd;
}
void	handle_output(t_doubly_lst *old_list, t_doubly_lst *node)
{
	char		*path;
	char		*dir;
	struct stat	fileStat;

	path = old_list->next->cmd;
	stat(path, &fileStat);
	if (S_ISDIR(fileStat.st_mode))
		return (put_error("minishell: is a directory: ", path, 1));
	else if (ft_strchr(path, '/'))
	{
		dir = get_dir(path);
		if (access(dir, F_OK) == -1)
		{
			put_error("minishell: No such file or directory: ", path, 1);
			return (free(dir));
		}
	}
	else if (access(path, W_OK) == -1 && access(path, F_OK) == 0)
		return (put_error("minishell: permission denied: ", path, 1));
	node->out = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
}
void	handle_append(t_doubly_lst *old_list, t_doubly_lst *node)
{
	char		*path;
	char		*dir;
	struct stat	fileStat;

	path = old_list->next->next->cmd;
	stat(path, &fileStat);
	if (S_ISDIR(fileStat.st_mode))
		return (put_error("minishell: is a directory: ", path, 1));
	else if (ft_strchr(path, '/'))
	{
		dir = get_dir(path);
		if (access(dir, F_OK) == -1)
		{
			put_error("minishell: No such file or directory: ", path, 1);
			return (free(dir));
		}
	}
	else if (access(path, W_OK) == -1 && access(path, F_OK) == 0)
		return (put_error("minishell: permission denied: ", path, 1));
	node->out = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
}

void	handle_heredoc(t_doubly_lst *old_list, t_doubly_lst *node,
		t_exec_context *exContext)
{
	char	*line;
	int		end[2];
	char	*delimiter;
	int		quotes;

	if (pipe(end) == -1)
		put_error("Error in readline\n", NULL, 0);
	delimiter = old_list->next->next->cmd;
	quotes = 1;
	if (ft_strchr(delimiter, '\"'))
	{
		quotes = 0;
		delimiter = remove_quotes(delimiter);
	}
	while (1)
	{
		line = readline("> ");
		if (!line)
			put_error("Error in readline\n", NULL, 0);
		if (ft_strncmp(delimiter, line, ft_strlen(line)) == 0 && line[0])
		{
			free(line);
			line = NULL;
			close(end[1]);
			break ;
		}
		if (quotes)
			line = expand_token(line, exContext);
		if (write(end[1], line, ft_strlen(line)) == -1)
			put_error("Error in readline\n", NULL, 0);
		else if (write(end[1], "\n", 1) == -1)
			put_error("Error in readline\n", NULL, 0);
		free(line);
	}
	if (line)
		free(line);
	node->in = end[0];
}
