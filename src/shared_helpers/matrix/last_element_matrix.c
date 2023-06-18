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
