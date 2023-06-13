/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:00:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/12 13:43:27 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_start_vars(t_env *env)
{
	char			*tmp;
	t_env_variable	*shl_lvl_elem;
	t_env_variable	*path_elem;

	shl_lvl_elem = search_env_elem(env, "SHLVL");
	if (shl_lvl_elem == NULL || ft_atoi(shl_lvl_elem->content) <= 1)
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
	print_env(env, 1);
	env->env_array = env_to_matrix(env->first);
}

int	init_data(t_exec_context *exContext, char **av, char **env_str)
{
	(void)av;
	exContext->cmds = NULL;
	exContext->env = env_to_list(env_str);
	set_start_vars(exContext->env);
	g_exit_status = 0;
	if (!exContext->env)
		return (1);
	// rl_catch_signals = 0;
	return (0);
}
