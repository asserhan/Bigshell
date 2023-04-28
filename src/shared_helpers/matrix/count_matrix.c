#include "../../../includes/minishell.h"

int	count_pointers(char **arr)
{
	int count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return (count);
}