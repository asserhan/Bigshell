/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:43:25 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:43:27 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_env_value(char *name, t_exec_context *ex_context)
{
	char			*result;
	t_env_variable	*match;

	result = NULL;
	match = search_env_elem(ex_context->env, name);
	if (match)
		result = ft_strdup(search_env_elem(ex_context->env, name)->content);
	return (result);
}
