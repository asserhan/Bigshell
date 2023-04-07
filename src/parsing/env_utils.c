/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:18:39 by otait-ta          #+#    #+#             */
/*   Updated: 2023/04/07 21:36:06 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* take a string from env matrix and convert it to a env node*/
t_env_variable	str_to_element(char *pair)
{
	t_env_variable	*new;

	new = ft_calloc(1, 1);
	(void)new;
	printf("%s", pair);
	return (*new);
}

t_env	*env_to_list(char **str)
{
	t_env			*env;
	int				i;
	t_env_variable	tmp_env;

	env = ft_calloc(sizeof(t_env *), 1);
	if (!env)
		return (NULL);
	env->env_array = str;
	i = 0;
	while (str[i])
	{
		tmp_env = str_to_element(str[i]);
		i++;
	}
	return (env);
}
