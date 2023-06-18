/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:00:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/17 15:51:00 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_start_vars(t_env *env)
{
	char			*tmp;
	t_env_variable	*shl_lvl_elem;
	t_env_variable	*path_elem;

	shl_lvl_elem = search_env_elem(env, "SHLVL");
	if (shl_lvl_elem == NULL || ft_atoi(shl_lvl_elem->content) <= 0)
		tmp = ft_strdup("1");
	else
		tmp = ft_itoa(ft_atoi(shl_lvl_elem->content) + 1);
	update_env_elem(env, "SHLVL", tmp);
	free(tmp);
	tmp = getcwd(NULL, 0);
	update_env_elem(env, "PWD", tmp);
	free(tmp);
	path_elem = search_env_elem(env, "PATH");
	if (!path_elem)
		update_env_elem(env, "PATH",
			"/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki");
	env->env_array = env_to_matrix(env->first);
}

int	init_data(t_exec_context *ex_context, char **av, char **env_str)
{
	(void)av;
	ex_context->cmds = NULL;
	ex_context->env = env_to_list(env_str);
	set_start_vars(ex_context->env);
	g_exit_status = 0;
	if (!ex_context->env)
		return (1);
	ex_context->fds = NULL;
	return (0);
}
