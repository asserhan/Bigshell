/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/21 18:49:32 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <string.h>

void	exec_builtins(t_exec_context *exContext)
{
	ft_printf("cmd: \n");
	if (ft_strcmp(exContext->cmds->cmd, "env") == 0)
		print_env(exContext->env, 1);
	ft_printf("cmd: \n");
	// if (ft_strcmp(exContext->cmds->cmd, "export") == 0)
	// 	set_env_elem(exContext->env, create_env_elem("wat"));
}
