/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_expend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:48:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/11 14:01:30 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*path_expand(char *str, char *home)
{
	char	*tmp;
	char	*tilde_expansion;
	int		quotes[2];
	int		i;
	char	*result;

	quotes[0] = 0;
	quotes[1] = 0;
	i = -1;
	while (str && str[++i])
	{
		handle_quotes(&quotes[0], &quotes[1], str[i]);
		if (!quotes[0] && !quotes[1] && str[i] == '~' && (i == 0
				|| (str[i - 1] != '$' && str[i - 1] != '\\')))
		{
			tmp = ft_substr(str, 0, i);
			tilde_expansion = ft_strjoin(tmp, home);
			free(tmp);
			tmp = ft_strdup(str + i + 1);
			result = ft_strjoin(tilde_expansion, tmp);
			free(tmp);
			return (free(tilde_expansion), path_expand(result, home));
		}
	}
	return (str);
}
