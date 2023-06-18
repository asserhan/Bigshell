/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:46:04 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/18 23:23:37 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_display(char **arg, int i, int fd)
{
	while (arg[i])
	{
		ft_putstr_fd(arg[i], fd);
		if (arg[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
}

int	ft_check_flag(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	if (str[i] == '-' && str[i + 1] == 'n')
	{
		i++;
		while (str[i] == 'n')
			i++;
	}
	if (str[i])
		return (1);
	return (0);
}

void	ft_echo(char **arg)
{
	int	i;
	int	flag;

	flag = FALSE;
	i = 1;
	if (count_matrix(arg) == 1)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	while (arg[i] && !ft_check_flag(arg[i]))
	{
		flag = TRUE;
		i++;
	}
	ft_display(arg, i, 1);
	if (flag == FALSE)
		ft_putstr_fd("\n", 1);
}
