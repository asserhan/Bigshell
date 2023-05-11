/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:29:20 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/11 14:25:11 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char **matrix_push_back(char **matrix, char *back)
{
    char **new_matrix;
    char *new_row;
    int count;
    int i;


    count = count_matrix(matrix);
    new_matrix = (char **)ft_calloc((count + 1) + 1, sizeof(char *));
    if (!new_matrix)
        return NULL;
    i = 0;
    while (matrix && matrix[i] != NULL) {
        new_matrix[i] = matrix[i];
        i++;
    }
    new_row = (char *)malloc(sizeof(char) * (ft_strlen(back) + 1));
    if (!new_row)
        return NULL;
    ft_strcpy(new_row, back);
    new_matrix[count] = new_row;
    return new_matrix;
}