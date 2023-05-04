/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:14 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/01 16:01:03 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int ft_pwd(void)
{
	char *buff;
	if (getcwd(buff,PATH_MAX) != NULL)
	{
		ft_putstr_fd(buff,1);
		ft_putstr_fd("\n",1);
	}
	else
	{
		perror("getcwd() error");
		return (1);
	}
	return (0);
}
