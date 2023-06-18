/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:16 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/18 19:41:51 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_valid_arg(char *arg)
{
	int		j;
	char	*alpha;

	alpha = ft_alpha();
	if (start_with(arg, alpha) == 0)
	{
		if (start_with(arg, "-"))
			put_error_ex("unset: ", arg, ": unset with no option\n", 1);
		else
			put_error_ex("minishell:  unset: ", arg,
				": not a valid identifier\n", 1);
		return (1);
	}
	j = 1;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]) && !ft_isalpha(arg[j]) && arg[j] != '_')
		{
			put_error_ex("minishell:  unset: ", arg,
				": not a valid identifier\n", 1);
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_unset(t_exec_context *ex_context)
{
	int				i;
	t_env_variable	*elem;

	if (count_matrix(ex_context->cmds->args) == 1)
		return ;
	else
	{
		i = 1;
		while (ex_context->cmds->args[i])
		{
			if (!is_valid_arg(ex_context->cmds->args[i]))
			{
				elem = search_env_elem(ex_context->env,
						ex_context->cmds->args[i]);
				if (!elem)
					return ;
				delete_env_elem(ex_context->env, elem);
				if (ft_strcmp(ex_context->cmds->args[i], "PATH") == 0)
					ex_context->is = 1;
			}
			else
				return ;
			i++;
		}
	}
}
