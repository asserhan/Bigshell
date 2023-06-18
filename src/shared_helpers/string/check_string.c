/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:09:26 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/10 19:17:27 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	start_with(char *str, char *set)
{
	if (ft_strchr(set, str[0]))
		return (str[0]);
	return (0);
}

char	end_with(char *str, char *set)
{
	if (ft_strchr(set, str[ft_strlen(str) - 1]))
		return (str[ft_strlen(str) - 1]);
	return (0);
}
