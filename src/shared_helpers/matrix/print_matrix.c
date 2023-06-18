/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:57:09 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/11 12:30:33 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_matrix(char **matrix, char separator)
{
	int	count;
	int	i;

	i = 0;
	count = count_matrix(matrix);
	while (i < count)
	{
		ft_putstr_fd(matrix[i], 1);
		ft_putchar_fd(separator, 1);
		i++;
	}
}
