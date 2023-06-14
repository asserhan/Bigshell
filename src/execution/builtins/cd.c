/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:56:51 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/14 17:48:44 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*get_env_path(t_env *env, char *name)
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

static void	update_pwd(t_env *env, char *name)
{
	t_env_variable	*tmp;
	char			pwd[PATH_MAX];
	char			*home;

	tmp = env->first;
	while (tmp)
	{
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
void	ft_cd(char **arg, t_env *env)
{
	char	*path;
	char	str[PATH_MAX];
	char	*oldpwd;

	if (count_matrix(arg) == 1)
	{
		path = go_home(env);
		chdir(path);
	}
	else
	{
		path = arg[1];
		if (!path)
			return ;
		if (chdir(path) == -1)
		{
			put_error_ex("minishell: cd: ", path,
					": No such file or directory\n", 1);
			return ;
		}
		if (!search_env_elem(env, "OLDPWD") || !search_env_elem(env, "PWD"))
		{
			if (!search_env_elem(env, "PWD"))
				update_env_elem(env, "OLDPWD", "\"\0\"");
			return ;
		}
		oldpwd = get_env_path(env, "PWD");
		path = getcwd(str, PATH_MAX);
		if (!path && errno == ENOENT)
		{
			ft_putstr_fd(" cd: error retrieving current directory: ", 2);
			ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
			ft_putstr_fd("No such file or directory\n", 2);
			g_exit_status = 0;
			return ;
		}
		update_oldpwd(env, "OLDPWD", oldpwd); 
		update_pwd(env, "PWD");
	}
	g_exit_status = 0;
}
