/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:36:54 by otait-ta          #+#    #+#             */
/*   Updated: 2023/04/07 22:42:57 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	if (matrix && matrix[0])
	{
		while (matrix[0][i])
		{
			free(matrix[0][i]);
			i++;
		}
	}
	if (matrix)
	{
		free(matrix[0]);
		*matrix = NULL;
	}
}
