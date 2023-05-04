/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:46:04 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/01 12:02:20 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*static int count_arg(char **arg)
{
	int i;
	i = 0;
	while (arg[i] != NULL)
		i++;
	return (i);
})*/

static void	ft_display(char **arg,int i,int fd)
{
	while (arg[i])
	{
		ft_putstr_fd(arg[i], fd);
		if (arg[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
}
void	ft_echo(char **arg)
{
	int i;
	int flag;
	flag = false;
	i = 1;
	while (arg[i] && ft_strcmp(arg[i], "-n") == 0)
	{
		flag = true;
		i++;
	}
	ft_display(arg, i, 1);
	if (flag == false)
		ft_putstr_fd("\n", 1);
}




