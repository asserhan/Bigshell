/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:36:54 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/11 14:52:53 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix && *matrix)
	{
		while (matrix[i])
		{
			if (matrix[i])
			{
				free(matrix[i]);
				matrix[i] = NULL;
			}
			i++;
		}
	}
	free(matrix);
	matrix = NULL;
}
