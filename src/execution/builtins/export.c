/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:12 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/22 13:40:56 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
/*Bubble sort*/
char **sort_env(t_env *env)
{
	char **arr;
	char *temp;
	int i;
	int sorted;

	arr = env->env_array;
	i = 0;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < env->size - 1)
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
	return (arr);
}
void print_export(t_exec_context *exContext)
{
	int i;
	i = 0;
	while (exContext->env->env_array[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(exContext->env->env_array[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
int ft_strpbrk(char *s1, char *s2)
{
	int i;
	if (!s1 || !s2)
		return (1);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return (0);
			i++;
		}
		s1++;
	}
	return (1);
}
void _export_parse(t_exec_context *exContext)
{
	t_env_variable *tmp;
	int i;
	if (start_with(exContext->cmds->args[0], "+@=*0123456789%"))
	{
		put_error_ex("minishell: export: ", exContext->cmds->args[0], ": not a valid identifier\n", 1);
		return;
	}
	i = 0;
	while (exContext->cmds->args[i])
	{
		if (ft_strchr(exContext->cmds->args[i], '='))
		{
			printf("has =\n");
			tmp = create_env_elem(exContext->cmds->args[i]);
			set_env_elem(exContext->env, tmp);
			// // free(tmp);
		}
		i++;
	}
	return;
}
void ft_export(t_exec_context *exContext)
{
	int i;
	i = 0;

	exContext->env->env_array = sort_env(exContext->env);
	if (exContext->cmds->args != NULL)
		_export_parse(exContext);
	else
		print_export(exContext);
	// set_env_elem(exContext->env, create_env_elem("wat"));
}
