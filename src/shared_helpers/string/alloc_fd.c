/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:44:25 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:44:25 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	*alloc_fd(int fd)
{
	int	*fd_tab;

	fd_tab = malloc(sizeof(int));
	if (!fd_tab)
		return (0);
	*fd_tab = fd;
	return (fd_tab);
}

void	add_fd(t_exec_context *ex_context, int fd)
{
	t_list	*fd_node;

	fd_node = ft_lstnew(alloc_fd(fd));
	ft_lstadd_back(&ex_context->fds, fd_node);
}
