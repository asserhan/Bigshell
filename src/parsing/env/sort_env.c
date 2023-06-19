/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:54:34 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/19 13:41:42 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env_variable	*creat_node(char *name, char *content)
{
	t_env_variable	*new;

	new = ft_calloc(sizeof(t_env_variable), 1);
	if (!new)
		return (NULL);
	new->name = ft_strdup(name);
	new->content = ft_strdup(content);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	add_back(t_env_variable **tail, t_env_variable *new_node)
{
	(*tail)->next = new_node;
	new_node->prev = *tail;
	*tail = new_node;
}

t_env_variable	*copy_env_var(t_env_variable *head)
{
	t_env_variable	*curr;
	t_env_variable	*new_head;
	t_env_variable	*tail;
	t_env_variable	*new_node;

	if (head == NULL)
		return (NULL);
	curr = head;
	new_head = NULL;
	tail = NULL;
	while (curr != NULL)
	{
		new_node = creat_node(curr->name, curr->content);
		if (new_head == NULL)
		{
			new_head = new_node;
			tail = new_node;
		}
		else
			add_back(&tail, new_node);
		curr = curr->next;
	}
	return (new_head);
}

t_env	*copy_env_list(t_exec_context *ex_context)
{
	t_env	*env;
	t_env	*new_env;

	new_env = ft_calloc(sizeof(t_env), 1);
	env = ex_context->env;
	new_env->first = copy_env_var(env->first);
	new_env->size = env->size;
	return (new_env);
}

void	sort_env_var(t_env_variable *head)
{
	t_env_variable	*curr;
	t_env_variable	*next_node;
	char			*tmp_name;
	char			*tmp_content;

	curr = head;
	while (curr != NULL)
	{
		next_node = curr->next;
		while (next_node != NULL)
		{
			if (ft_strcmp(curr->name, next_node->name) > 0)
			{
				tmp_name = curr->name;
				curr->name = next_node->name;
				next_node->name = tmp_name;
				tmp_content = curr->content;
				curr->content = next_node->content;
				next_node->content = tmp_content;
			}
			next_node = next_node->next;
		}
		curr = curr->next;
	}
}
