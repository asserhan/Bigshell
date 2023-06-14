/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:12 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/14 20:53:51 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_export(t_env *env)
{
	t_env_variable	*tmp;

	sort_env_var(env->first);
	tmp = env->first;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->name, 1);
		if (tmp->content[0] != '\0')
		{
			ft_putstr_fd("=", 1);
			ft_printf("\"%s\"", tmp->content);
		}
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
}

int	first_char(char *arg)
{
	char	*alpha;

	alpha = ft_alpha();
	if (start_with(arg, alpha) == 0)
	{
		if (start_with(arg, "-"))
			put_error_ex("export: ", arg, ": export with no option\n", 1);
		else
			put_error_ex("minishell:  export: ", arg,
				": not a valid identifier\n", 1);
		return (1);
	}
	return (0);
}

int	_export_parse(char *arg)
{
	int		j;
	char	*alpha;

	alpha = ft_alpha();
	if (first_char(arg) == 1)
		return (1);
	j = 1;
	while (arg[j] && arg[j] != '=')
	{
		if (arg[j] == '+' && arg[j + 1] == '=')
			return (0);
		if (!ft_isdigit(arg[j]) && !ft_isalpha(arg[j]) && arg[j] != '_')
		{
			put_error_ex("minishell:  export: ", arg,
				": not a valid identifier\n", 1);
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_export(t_exec_context *exContext)
{
	t_env	*copy;
	int		i;

	if (count_matrix(exContext->cmds->args) > 1)
	{
		i = 1;
		while (exContext->cmds->args[i])
		{
			if (!_export_parse(exContext->cmds->args[i]))
				_export_variable(exContext->cmds->args[i], exContext->env);
			i++;
		}
	}
	else
	{
		copy = copy_env_list(exContext);
		print_export(copy);
		free_env(&copy);
	}
}
