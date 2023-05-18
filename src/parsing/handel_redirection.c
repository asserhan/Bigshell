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

void	handle_output(t_doubly_lst *old_list, t_doubly_lst *node)
{
	int		fd;
	char	*file_name;

	file_name = old_list->next->cmd;
	fd = open(file_name, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		ft_putstr_fd("could not creat or open the file ", 2);
	node->out = fd;
}

void	handle_input(t_doubly_lst *old_list, t_doubly_lst *node)
{
	int		fd;
	char	*file_name;

	file_name = old_list->next->cmd;
	fd = open(file_name, O_RDONLY | O_APPEND);
	if (fd == -1)
		ft_putstr_fd("minishell: No such file or directory ", 2);
	node->in = fd;
}

void	handle_append(t_doubly_lst *old_list, t_doubly_lst *node)
{
	int		fd;
	char	*file_name;

	file_name = old_list->next->next->cmd;
	fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		ft_putstr_fd("could not creat or open the file ", 2);
	node->in = fd;
}
