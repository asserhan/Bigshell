/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:03 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/11 15:26:24 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_env(t_exec_context *exContext, t_doubly_lst *commend)
{
	t_doubly_lst	*cmds;

	cmds = commend;
	if (exContext->is == 1)
	{
		put_error_ex("minishell: ", cmds->args[0],
				": No such file or directory\n", 127);
		return ;
	}
	if (count_matrix(cmds->args) == 1)
		print_env(exContext->env, 1);
	else
	{
		if (ft_strcmp(cmds->args[1], "--") == 0 || start_with(cmds->args[1],
				";"))
			print_env(exContext->env, 1);
		else if (start_with(cmds->args[1], "="))
			put_error_ex("env: ", cmds->args[1], ": Invalid argument\n", 127);
		else if (start_with(cmds->args[1], "-"))
			g_exit_status = 0;
		else if (start_with(cmds->args[1], "./"))
			put_error_ex("env: ", cmds->args[1], ": Permission denied\n", 126);
		else
			put_error_ex("env: ", cmds->args[1],
					": No such file or directory \n", 127);
		return ;
	}
}
