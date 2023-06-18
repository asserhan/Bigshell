/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:44:40 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:44:40 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	put_error(char *message, char *param, int status_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	if (param)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
	g_exit_status = status_code;
}

void	put_error_ex(char *message, char *param, char *suffix, int status_code)
{
	ft_putstr_fd(message, 2);
	if (param)
		ft_putstr_fd(param, 2);
	if (suffix)
		ft_putstr_fd(suffix, 2);
	g_exit_status = status_code;
}

void	ft_msg_error(char *message, int exit_s)
{
	perror(message);
	if (errno == EACCES)
	{
		g_exit_status = 126;
		exit(g_exit_status);
	}
	g_exit_status = exit_s;
	exit(g_exit_status);
}
