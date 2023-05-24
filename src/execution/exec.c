/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:48:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/24 19:35:16 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <string.h>

void	exec_builtins(t_exec_context *exContext)
{
	if (ft_strcmp(exContext->cmds->cmd, "env") == 0)
		ft_env(exContext);

	if (ft_strcmp(exContext->cmds->cmd, "export") == 0)
		ft_export(exContext);
	if(ft_strcmp(exContext->cmds->cmd, "echo") == 0)
		ft_echo(exContext->cmds->args);
	if(ft_strcmp(exContext->cmds->cmd, "unset") == 0)
		ft_unset(exContext);


}
