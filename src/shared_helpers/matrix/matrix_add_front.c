
#include "../../../includes/minishell.h"

char	**matrix_add_front(char *str, char **matrix)
{
	int i;
	int len;
	char **new_matrix;

	len = count_matrix(matrix);
	new_matrix = malloc(sizeof(char *) * (len + 2));
	if (!new_matrix)
		return (NULL);
	new_matrix[0] = ft_strdup(str);
	i = 0;
	if (!matrix)
	{
		new_matrix[1] = NULL;
		return (new_matrix);
	}
	while (matrix[i])
	{
		new_matrix[i + 1] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i + 1] = NULL;
	free_matrix(matrix);
	return (new_matrix);
}