
#include "../../../includes/minishell.h"

int	find_char_index(const char *str, const char *set)
{
	if (!str || !set)
		return (-1);

	int i = 0;
	while (str[i])
	{
		if (strchr(set, str[i]))
			return (i);
		i++;
	}

	return (-1);
}