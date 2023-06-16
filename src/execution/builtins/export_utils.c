/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:49:11 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/14 20:56:08 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*ft_elimine_char(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen(str));
	if (!new)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			str++;
		new[i++] = *str++;
	}
	new[i] = '\0';
	return (new);
}

static char	*ft_joining(char const *s1, char const *s2)
{
	char	*p;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(len + 1 * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		ft_strlcpy(p, s1, ft_strlen(s1) + 1);
		ft_strlcat(p, s2, len + 1);
		free((char *)s1);
	}
	return (p);
}

static void	add_to_variable(char *var, int i, t_env *env)
{
	char			*s;
	char			*str;
	t_env_variable	*tmp;

	s = ft_substr(var, 0, i);
	var = ft_elimine_char(var, '+');
	str = ft_substr(var, i + 1, ft_strlen(var));
	tmp = search_env_elem(env, s);
	if (!tmp)
		tmp = create_env_elem(var);
	else
	{
		s = ft_joining(s, "=");
		s = ft_joining(s, tmp->content);
		s = ft_joining(s, str);
		delete_env_elem(env, tmp);
		tmp = create_env_elem(s);
	}
	set_env_elem(env, tmp);
	(free(s), free(str), free(var));
}

void	_export_variable(char *arg, t_env *env)
{
	t_env_variable	*tmp;
	char			*var;
	char			*s;
	int				i;

	var = arg;
	i = 0;
	while (arg[i] && var[i] != '=' && var[i] != '+')
		i++;
	if (var[i] == '+')
		add_to_variable(var, i, env);
	else
	{
		s = ft_substr(var, 0, i);
		tmp = search_env_elem(env, s);
		if (tmp != NULL)
			delete_env_elem(env, tmp);
		tmp = create_env_elem(arg);
		set_env_elem(env, tmp);
		free(s);
	}
}
