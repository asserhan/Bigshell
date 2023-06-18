#include "../../../includes/minishell.h"

int	find_char_index(const char *str, const char *set)
{
	int	i;

	i = 0;
	if (!str || !set)
		return (-1);
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (-1);
}
