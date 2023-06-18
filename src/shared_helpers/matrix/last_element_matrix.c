/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_element_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:44:09 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:44:10 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*last_element_matrix(char **matrix)
{
	int	i;
	int	len;

	len = count_matrix(matrix);
	if (len == 0)
		return (NULL);
	i = 0;
	while (matrix[i])
		i++;
	return (matrix[i - 1]);
}
