/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:00:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/04/08 03:13:02 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_data(t_exec_context *exContext, char **av, char **env_str)
{
	(void)av;
	exContext->cmds = NULL;
	exContext->env = env_to_list(env_str);
	return (0);
}