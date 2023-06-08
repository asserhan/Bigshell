/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:56:51 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/08 18:58:56 by hasserao         ###   ########.fr       */
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
void	ft_cd(char **arg, t_env *env)
{
	char	*path;

	if (count_matrix(arg) == 1)
	{
		path = get_env_path(env, "HOME");
		chdir(path);
	}
	else
	{
		path = arg[1];
		if (chdir(path) == -1)
		{
			put_error_ex("minishell: cd: ", path, ": No such file or directory\n",
					1);
			return ;
		}
		update_pwd(env, "PWD");
		update_pwd(env, "OLDPWD"); //to do
	}
}
