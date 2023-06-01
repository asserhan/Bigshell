/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:18:39 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/01 10:51:46 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void set_env_elem(t_env *env, t_env_variable *new_env)
{
	t_env_variable *tmp;

	if (env->first == NULL)
		env->first = new_env;
	else
	{
		tmp = env->first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_env;
		new_env->prev = tmp;
	}
	env->size++;
}

void print_env(t_env *env, int fd)
{
	t_env_variable *tmp;

	tmp = env->first;
	while (tmp)
	{
		if (tmp->content[0] || ft_strchr(tmp->name,'='))
		{
			ft_printf("%s",tmp->name);
			if (!ft_strchr(tmp->name,'='))
				ft_putstr_fd("=",fd);
			ft_printf("%s",tmp->content);

				ft_putstr_fd("\n",fd);
		}
		tmp = tmp->next;
	}
}

t_env *env_to_list(char **str)
{
	t_env *env;
	int i;
	t_env_variable *tmp_env;

	env = ft_calloc(sizeof(t_env), 1);
	if (!env)
		return (NULL);
	env->env_array = str;
	i = 0;
	while (str[i])
	{
		tmp_env = create_env_elem(str[i]);
		if (!tmp_env)
			return (NULL);
		set_env_elem(env, tmp_env);
		i++;
	}
	return (env);
}

char *str_to_env_form(char *s1, char *s2)
{
	char *p1;
	char *rtr;

	p1 = ft_strjoin(s1, "=");
	if (!p1)
		return (NULL);
	rtr = ft_strjoin(p1, s2);
	free(p1);
	return (rtr);
}
