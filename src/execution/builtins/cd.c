/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:06:59 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/04 01:27:10 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
static char *go_home(t_env *env)
{
	t_env_variable *tmp;
	tmp = env->first;
	while(tmp)
	{
		if(ft_strcmp(tmp->name,"HOME") == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);

}
static char *get_env_path(t_env *env,char *name)
{
	t_env_variable *tmp;
	tmp = env->first;
	while(tmp)
	{
		if(ft_strcmp(tmp->name,name) == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
static void update_pwd(t_env *env,char *name)
{
	t_env_variable *tmp;
	char *pwd[PATH_MAX];
	tmp = env->first;
	while (tmp)
	{
		if (ft_strcmp(tmp->name,name)==0)
		{
			free(tmp->content);
			if(getcwd(pwd,PATH_MAX) == NULL)
				return ;
			tmp->content = ft_strdup(pwd);
		}
		tmp = tmp->next;
	}
	
}
void ft_cd(char **arg,t_env *env)
{
	char *path;
	char *new_path;
	if(arg[1] == NULL)
		path = get_env_path(env,"HOME");
	else
		path = arg[1];
	if (ft_strcmp(path,"-") == 0)
	{
		new_path = get_env_path(env,"OLDPWD");
		if (new_path == NULL)
		{
			ft_putstr_fd("cd: OLDPWD not set\n",2);
			return ;
		}
		update_pwd(env,"OLDPWD");
	}

}
