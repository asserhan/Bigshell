/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:23:57 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/14 18:49:52 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_env_path(t_env *env, char *name)
{
	t_env_variable	*tmp;

	tmp = env->first;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*go_home(t_env *env)
{
	char	*home;

	home = get_env_path(env, "HOME");
	if (!home)
	{
		put_error_ex("minishell: cd: HOME not set\n", NULL, NULL, 1);
		return (NULL);
	}
	return (home);
}

static void	find_pwd(t_env *env, t_env_variable *tmp, char *name)
{
	char	pwd[PATH_MAX];
	char	*home;

	if (ft_strcmp(tmp->name, name) == 0)
	{
		free(tmp->content);
		if (getcwd(pwd, PATH_MAX))
			tmp->content = ft_strdup(pwd);
		else
		{
			if (search_env_elem(env, "OLDPWD"))
				tmp->content = ft_strdup(search_env_elem(env,
							"OLDPWD")
						->content);
			else
			{
				home = get_env_path(env, "HOME");
				tmp->content = ft_strdup(home);
			}
		}
	}
}

void	update_pwd(t_env *env, char *name)
{
	t_env_variable	*tmp;

	tmp = env->first;
	while (tmp)
	{
		find_pwd(env, tmp, name);
		tmp = tmp->next;
	}
}

void	update_oldpwd(t_env *env, char *name, char *path)
{
	t_env_variable	*tmp;

	tmp = env->first;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			free(tmp->content);
			tmp->content = ft_strdup(path);
			return ;
		}
		tmp = tmp->next;
	}
}
