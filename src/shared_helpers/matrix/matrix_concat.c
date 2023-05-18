/* ************************************************************************** */
/* */
/* ::: :::::::: */
/* matrix_concat.c :+: :+: :+: */
/* +:+ +:+ +:+ */
/* By: otait-ta <otait-ta@student.42.fr> +#+ +:+ +#+ */
/* +#+#+#+#+#+ +#+ */
/* Created: 2023/05/04 11:40:42 by otait-ta #+# #+# */
/* Updated: 2023/05/04 11:44:13 by otait-ta ### ########.fr */
/* */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**matrix_concat(char **matrix, char **back)
{
	int		matrix_len;
	int		back_len;
	char	**result;
	int		i;

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
	i = 0;
	while (i < back_len)
	{
		result[matrix_len + i] = ft_strdup(back[i]);
		i++;
	}
	result[matrix_len + back_len] = NULL;
	return (free_matrix(matrix), result);
}
