/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:04:59 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/06 23:05:02 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	count_matrix(char **arr)
{
	int	count;

	count = 0;
	if (!arr)
		return (0);
	while (*arr != NULL)
	{
		count++;
		arr++;
	}
	return (count);
}
