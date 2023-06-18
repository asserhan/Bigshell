/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:03 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/14 18:56:10 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	ft_unset_path(t_exec_context *ex_context, t_doubly_lst *cmd)
{
	if (ex_context->is == 1)
	{
		put_error_ex("minishell: ", cmd->args[0],
			": No such file or directory\n", 127);
		return (1);
	}
	return (0);
}

void	ft_env(t_exec_context *ex_context)
{
	t_doubly_lst	*cmds;

	cmds = ex_context->cmds;
	if (ft_unset_path(ex_context, cmds))
		return ;
	if (count_matrix(cmds->args) == 1)
		print_env(ex_context->env, 1);
	else
	{
		if (ft_strcmp(cmds->args[1], "--") == 0 || start_with(cmds->args[1],
				";"))
			print_env(ex_context->env, 1);
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
