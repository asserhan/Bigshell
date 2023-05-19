/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:01:03 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/18 17:17:57 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_dir(char *path)
{
	char	*dir;
	int		i;

	i = ft_strlen(path);
	while (path[i] != '/')
		i--;
	dir = ft_substr(path, 0, i);
	return (dir);
}

void	handle_output(t_doubly_lst *old_list, t_doubly_lst *node)
{
	char		*path;
	char		*dir;
	struct stat	fileStat;

	path = old_list->next->cmd;
	stat(path, &fileStat);
	dir = get_dir(path);
	if (S_ISDIR(fileStat.st_mode))
		put_error("minishell: is a directory: ", path, 1);
	else if (access(dir, F_OK) == -1)
		put_error("minishell: No such file or directory: ", path, 1);
	else if (access(path, W_OK) == -1 && access(path, F_OK) == 0)
		put_error("minishell: permission denied: ", path, 1);
	node->out = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(dir);
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

void	handle_append(t_doubly_lst *old_list, t_doubly_lst *node)
{
	char		*path;
	char		*dir;
	struct stat	fileStat;

	path = old_list->next->cmd;
	stat(path, &fileStat);
	dir = get_dir(path);
	if (S_ISDIR(fileStat.st_mode))
		put_error("minishell: is a directory: ", path, 1);
	else if (access(dir, F_OK) == -1)
		put_error("minishell: No such file or directory: ", path, 1);
	else if (access(path, W_OK) == -1 && access(path, F_OK) == 0)
		put_error("minishell: permission denied: ", path, 1);
	node->out = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	free(dir);
}
