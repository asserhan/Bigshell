/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:57:09 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/04 13:00:30 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void print_matrix(char **matrix,char *separator)
{
while(matrix && *matrix)
{
    printf("%s%s",*matrix,separator);
    matrix++;
}
}