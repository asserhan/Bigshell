/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:09 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/27 17:29:51 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exit(char **arg) 
{
	if (count_matrix(arg) == 1)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (arg[1] && !parse_arg(arg[1]))
	{
		ft_putstr_fd("exit\n", 1);
		put_error_ex("minishell: exit: ", arg[1], ": numeric argument required\n", 255);
		exit(255);
	}
	if (count_matrix(arg) >= 3)
	{
		ft_putstr_fd("exit\n", 1);
		put_error_ex("minishell: exit:", NULL, "too many arguments \n", 1);
	}
	else 
	{
		ft_putstr_fd("exit\n", 1);
		exit(ft_atoi(*arg));
	}
}
