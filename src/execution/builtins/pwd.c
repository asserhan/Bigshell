/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:38:40 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/09 21:03:45 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_pwd(void)
{
	char	buff[PATH_MAX];

	getcwd(buff, PATH_MAX);
	ft_putstr_fd(buff, 1);
	ft_putstr_fd("\n", 1);
	g_exit_status = 0;
	return (0);
}
