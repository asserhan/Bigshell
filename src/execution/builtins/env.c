/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:03 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/03 16:39:10 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int	exit_status;
void	ft_env(t_exec_context *exContext)
{
	t_doubly_lst	*cmds;

	cmds = exContext->cmds;
	if(exContext->is == 1)
		return ;
	if (count_matrix(cmds->args) == 1)
	{
		if (!ft_strcmp(cmds->cmd, "env="))
			return ;
		else
			print_env(exContext->env, 1);
	}
	else
	{
		if (ft_strcmp(cmds->args[1], "--") == 0 || start_with(cmds->args[1],
				";"))
			print_env(exContext->env, 1);
		else if (start_with(cmds->args[1], "="))
			put_error_ex("env: ", cmds->args[1], ": Invalid argument\n", 127);
		else if (start_with(cmds->args[1], "-"))
			exit_status = 0;
		else if (start_with(cmds->args[1], "./"))
			put_error_ex("env: ", cmds->args[1], ": Permission denied\n", 126);
		else
			put_error_ex("env: ", cmds->args[1],
					": No such file or directory \n", 127);
		return ;
	}
}
