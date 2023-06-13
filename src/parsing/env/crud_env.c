/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crud_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:53:42 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/23 16:57:03 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	delete_env_elem(t_env *list, t_env_variable *elem)
{
	if (elem != NULL)
	{
		if (elem == list->first)
			list->first = elem->next;
		if (elem->prev != NULL)
			elem->prev->next = elem->next;
		if (elem->next != NULL)
			elem->next->prev = elem->prev;
		free(elem->content);
		free(elem->name);
		free(elem);
		list->size--;
		elem = NULL;
	}
}

t_env_variable	*search_env_elem(t_env *env, char *name)
{
	t_env_variable	*match;

	match = env->first;
	while (match != NULL && ft_strcmp(match->name, name) != 0)
		match = match->next;
	if (match && ft_strcmp(match->name, name) != 0)
		return (NULL);
	return (match);
}

void	create_normal_env(t_env_variable *new, char *pair)
{
	int	equal_index;

	equal_index = ft_strchr(pair, '=') - pair;
	new->name = ft_substr(pair, 0, equal_index);
	if (!new->name)
	{
		free(new);
		new = NULL;
	}
	new->content = ft_substr(pair, equal_index + 1, ft_strlen(pair)
			- equal_index);
	if (!new->content)
	{
		free(new->name);
		free(new);
		new = NULL;
	}
}

t_env_variable	*create_env_elem(char *pair)
{
	t_env_variable	*new;

	new = ft_calloc(sizeof(t_env_variable), 1);
	if (!new)
		return (NULL);
	if (end_with(pair, "="))
	{
		new->name = ft_strdup(pair);
		new->content = ft_strdup("");
		return (new);
	}
	if (!ft_strchr(pair, '='))
	{
		new->name = ft_strdup(pair);
		if (!new->name)
			return (NULL);
		new->content = ft_strdup("");
		return (new);
	}
	create_normal_env(new, pair);
	return (new);
}

void	update_env_elem(t_env *env, char *name, char *new_content)
{
	t_env_variable	*match;
	char			*new_pair;

	match = search_env_elem(env, name);
	if (match)
		delete_env_elem(env, match);
	new_pair = str_to_env_form(name, new_content);
	match = create_env_elem(new_pair);
	set_env_elem(env, match);
	free(new_pair);
}
