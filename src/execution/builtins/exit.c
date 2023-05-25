/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:09 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/25 04:50:53 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int count_arg(char **arg)
{
	int i;
	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
}
void ft_exit(char **arg)
{
	if(!arg)
		exit(0);
	if(*arg && !ft_isdigit(**arg))
		put_error_ex("exit: ", *arg, ": numeric argument required\n", 255);
	else if(count_arg(arg)>=2)
		put_error_ex("exit: ", NULL, ": too many arguments \n", 1);
	else if (count_arg(arg) == 1)
		exit(0);
	else
		exit(ft_atoi(*arg));

}
