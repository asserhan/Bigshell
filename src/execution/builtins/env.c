/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:03 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/21 22:29:02 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

extern int exit_status;
void ft_env(t_exec_context *exContext)
{
	t_doubly_lst *cmds;

	cmds = exContext->cmds;
	if (cmds->args == NULL)
	{
		if (ft_strcmp(cmds->cmd, "env=") == 0)
			return;
		else
			print_env(exContext->env, 1);
	}
	else
	{
		if (ft_strcmp(cmds->args[0], "--") == 0 || start_with(cmds->args[0], ";"))
			print_env(exContext->env, 1);
		else if (start_with(cmds->args[0], "="))
			put_error_ex("env: ", cmds->args[0], ": Invalid argument\n", 127);
		else if (start_with(cmds->args[0], "-"))
			exit_status = 0;
		else if (start_with(cmds->args[0], "./"))
			put_error_ex("env: ", cmds->args[0], ": Permission denied\n", 126);
		else
			put_error_ex("env: ", cmds->args[0], ": No such file or directory \n", 127);
		return;
	}
}
