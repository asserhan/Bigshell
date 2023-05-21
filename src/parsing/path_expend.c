/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_expend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:48:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/03 14:24:30 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*path_expand(char *str, char *home)
{
	char *before_tilde;
	char *tilde_expansion;
	char *after_tilde;
	int quotes[2];
	int i;

	quotes[0] = 0;
	quotes[1] = 0;
	i = -1;
	while (str && str[++i])
	{
		handle_quotes(&quotes[0], &quotes[1], str[i]);
		if (!quotes[0] && !quotes[1] && str[i] == '~' && (i == 0 || (str[i
					- 1] != '$' && str[i - 1] != '\\')))
		{
			before_tilde = ft_substr(str, 0, i);
			tilde_expansion = ft_strjoin(before_tilde, home);
			free(before_tilde);
			after_tilde = ft_strdup(str + i + 1);
			str = ft_strjoin(tilde_expansion, after_tilde);
			free(after_tilde);
			free(tilde_expansion);
			return (path_expand(str, home));
		}
	}
	return (str);
}