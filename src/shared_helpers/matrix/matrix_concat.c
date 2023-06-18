/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:04:27 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/06 23:05:34 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**matrix_concat(char **matrix, char **back)
{
	int		matrix_len;
	int		back_len;
	char	**result;
	int		i;
	char	*tmp;

	matrix_len = count_matrix(matrix);
	back_len = count_matrix(back);
	result = ft_calloc((matrix_len + back_len + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < matrix_len)
	{
		result[i] = ft_strdup(matrix[i]);
		i++;
	}
	i = -1;
	while (++i < back_len)
	{
		tmp = ft_strdup(back[i]);
		result[matrix_len + i] = tmp;
	}
	result[matrix_len + back_len] = NULL;
	return (free_matrix(matrix), result);
}
