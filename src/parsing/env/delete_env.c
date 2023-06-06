/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:05:02 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/01 10:25:28 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	env_lstclear(t_env *env)
{
	if (!env)
		return ;
	while (env->first)
	{
		delete_env_elem(env, env->first);
		env->first = env->first->next;
	}
	env = NULL;
}
