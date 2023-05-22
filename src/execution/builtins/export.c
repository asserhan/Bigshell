/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:12 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/22 23:25:28 by hasserao         ###   ########.fr       */
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
void print_export(char **arr)
{
	int i;
	i = 0;
	while (arr[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(arr[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
// void print_export(t_env *env)
// {

// }

int _export_parse(char *arg)
{

	int j;
	char *alpha;
	alpha = ft_alpha();
	if (start_with(arg, alpha) == 0)
	{
		put_error_ex("minishell:  export: ", arg, ": not a valid identifier\n", 1);
		return (1);
	}
	j = 1;
	while (arg[j] && arg[j] != '=')
	{
		if(!ft_isdigit(arg[j]) && !ft_isalpha(arg[j]) && arg[j] != '_')
		{
			put_error_ex("minishell:  export: ", arg, ": not a valid identifier\n", 1);
			return (1);
		}
		j++;
	}
	return (0);
}

void ft_export(t_exec_context *exContext)
{

	t_env_variable *tmp;
	int i;

	if (exContext->cmds->args != NULL)
	{
		puts("here1");
		i = 0;
		while (exContext->cmds->args[i])
		{
			if (_export_parse(exContext->cmds->args[i]) == 0)
			{
				tmp = create_env_elem(exContext->cmds->args[i]);
				set_env_elem(exContext->env, tmp);
			}
			else
				return;
			i++;
		}
	}
	else
	{
		// int i=0;
		// while (exContext->env->env_array[i])
		// {
		// 	printf("%s\n", exContext->env->env_array[i]);
		// 	i++;
		// }
		exContext->env->env_array = sort_env(exContext->env);
		puts("here2");
		print_export(exContext->env->env_array);
	}
}
