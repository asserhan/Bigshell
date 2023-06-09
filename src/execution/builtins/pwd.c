/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:38:40 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/09 15:46:03 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	g_exit_status;
int	ft_pwd(void)
{
	char	buff[PATH_MAX];

	getcwd(buff, PATH_MAX);
	ft_putstr_fd(buff, 1);
	ft_putstr_fd("\n", 1);
	g_exit_status = 0;
	return (0);
}
