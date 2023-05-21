/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/21 19:39:02 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <string.h>

void	exec_builtins(t_exec_context *exContext)
{
	if (ft_strcmp(exContext->cmds->cmd, "env") == 0)
		ft_env(exContext);

	// if (ft_strcmp(exContext->cmds->cmd, "export") == 0)
	// 	set_env_elem(exContext->env, create_env_elem("wat"));
}
