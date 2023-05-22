/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:54:34 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/22 23:26:52 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env_variable *creat_node(char *name, char *content)
{
	t_env_variable *new;
	new = ft_calloc(sizeof(t_env_variable), 1);
	if (!new)
		return (NULL);
	new->name = ft_strdup(name);
	new->content = ft_strdup(content);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_env_variable *copy_env_var(t_env_variable *head)
{
	if (head == NULL)
		return NULL;
	t_env_variable *curr = head;
	t_env_variable *new_head = NULL;
	t_env_variable *tail = NULL;
	while (curr != NULL)
	{
		t_env_variable *new_node = creat_node(curr->name, curr->content);
		if (new_head == NULL)
		{
			new_head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
		curr = curr->next;
	}
	return (new_head);
}
t_env *copy_env_list(t_exec_context *exContext)
{
	t_env *env;
	t_env *new_env = NULL;
	env = exContext->env;
	new_env->first = copy_env_var(env->first);
	new_env->size = env->size;
	return (new_env);
}
