/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:00:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/04/07 21:24:16 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_data(t_exec_context *exContext, char **av, char **env)
{
	(void)av;
	exContext->cmds = NULL;
	exContext->env = env_to_list(env);
	return (0);
}