/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:09 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/18 23:16:40 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_space(int c)
{
	return (c == ' ');
}

int	parse_arg(char *str)
{
	int	i;
	int	digit_count;

	i = 0;
	digit_count = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		digit_count++;
		i++;
	}
	while (is_space(str[i]))
		i++;
	if ((str[i] == '\0' && digit_count))
		return (1);
	return (0);
}

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
		put_error_ex("minishell: exit: ", arg[1],
			": numeric argument required\n", 255);
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
