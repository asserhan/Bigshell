/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:12 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/19 13:24:10 by otait-ta         ###   ########.fr       */
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
	int	j;

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

void	ft_export(t_exec_context *ex_context)
{
	t_env	*copy;
	int		i;

	if (count_matrix(ex_context->cmds->args) > 1)
	{
		i = 1;
		while (ex_context->cmds->args[i])
		{
			if (!_export_parse(ex_context->cmds->args[i]))
				_export_variable(ex_context->cmds->args[i], ex_context->env);
			i++;
		}
	}
	else
	{
		copy = copy_env_list(ex_context);
		print_export(copy);
		free_env(&copy);
	}
}
