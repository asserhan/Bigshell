/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:09 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/27 00:34:42 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void ft_exit(char **arg) //parse first argument
{
	if(count_matrix(arg) == 1)
	{
		ft_putstr_fd("exit\n",1);
		exit(0);
	}
	else if(count_matrix(arg)>=3)
		put_error_ex("exit: ", NULL, ": too many arguments \n", 1);
	else if(arg[1] && !is_digit(arg[1]))
		put_error_ex("exit: ", *arg, ": numeric argument required\n", 255);
	else
	{
		ft_putstr_fd("exit\n",1);
		exit(ft_atoi(*arg));
	}

}
