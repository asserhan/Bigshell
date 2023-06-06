/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:57:39 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/04 17:57:42 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;
int	ft_pwd(void)
{
	char	buff[PATH_MAX];

	if (getcwd(buff, PATH_MAX) != NULL)
	{
		ft_putstr_fd(buff, 1);
		ft_putstr_fd("\n", 1);
		g_exit_status = 0;
	}
	else
	{
		perror("getcwd()");
		return (1);
	}
	return (0);
}
