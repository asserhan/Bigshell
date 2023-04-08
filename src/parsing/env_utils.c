/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:18:39 by otait-ta          #+#    #+#             */
/*   Updated: 2023/04/08 03:35:50 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_variable	*str_to_env_elem(char *pair)
{
	t_env_variable	*new;
	int				equal_index;

	new = ft_calloc(sizeof(t_env_variable), 1);
	if (!new)
		return (NULL);
	equal_index = ft_strchr(pair, '=') - pair;
	new->name = ft_substr(pair, 0, equal_index);
	if (!new->name)
		return (NULL);
	new->content = ft_substr(pair, equal_index + 1, ft_strlen(pair)
			- equal_index);
	if (!new->content)
		return (free(new->name), NULL);
	return (new);
}

void	set_env_elem(t_env *env, t_env_variable *new_env)
{
	t_env_variable	*tmp;

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

void	print_env(t_env *env, int fd)
{
	t_env_variable	*tmp;

	tmp = env->first;
	while (tmp)
	{
		ft_putstr_fd(tmp->name, fd);
		ft_putstr_fd("=", fd);
		ft_putstr_fd(tmp->content, fd);
		ft_putstr_fd("\n", fd);
		tmp = tmp->next;
	}
}

t_env	*env_to_list(char **str)
{
	t_env			*env;
	int				i;
	t_env_variable	*tmp_env;

	env = ft_calloc(sizeof(t_env), 1);
	if (!env)
		return (NULL);
	env->env_array = str;
	i = 0;
	while (str[i])
	{
		tmp_env = str_to_env_elem(str[i]);
		if (!tmp_env)
			return (NULL);
		set_env_elem(env, tmp_env);
		i++;
	}
	return (env);
}
