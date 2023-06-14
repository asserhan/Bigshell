/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:56:51 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/14 18:32:58 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	cd_errno(char *path)
{
	if (!path && errno == ENOENT)
	{
		ft_putstr_fd(" cd: error retrieving current directory: ", 2);
		ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
		g_exit_status = 0;
		return (1);
	}
	return (0);
}

static int	unset_pwd(t_env *env)
{
	if (!search_env_elem(env, "OLDPWD") || !search_env_elem(env, "PWD"))
	{
		if (!search_env_elem(env, "PWD"))
			update_env_elem(env, "OLDPWD", "\"\0\"");
		return (1);
	}
	return (0);
}

static int	ft_chdir(char *path)
{
	if (chdir(path) == -1)
	{
		put_error_ex("minishell: cd: ", path, ": No such file or directory\n",
			1);
		return (1);
	}
	return (0);
}

static void	ft_update(t_env *env, char *oldpwd)
{
	update_oldpwd(env, "OLDPWD", oldpwd);
	update_pwd(env, "PWD");
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
		if (ft_chdir(path))
			return ;
		if (unset_pwd(env))
			return ;
		oldpwd = get_env_path(env, "PWD");
		path = getcwd(str, PATH_MAX);
		if (cd_errno(path))
			return ;
		ft_update(env, oldpwd);
	}
	g_exit_status = 0;
}
