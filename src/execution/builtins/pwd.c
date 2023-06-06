// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pwd.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/01 11:07:14 by hasserao          #+#    #+#             */
// /*   Updated: 2023/05/01 16:01:03 by hasserao         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int exit_status;
int ft_pwd(void)
{
	char buff[PATH_MAX];
	if (getcwd(buff,PATH_MAX) != NULL)
	{
		ft_putstr_fd(buff,1);
		ft_putstr_fd("\n",1);
		exit_status = 0;
	}
	else
	{
		perror("getcwd()");
		return (1);
	}
	return (0);
}
