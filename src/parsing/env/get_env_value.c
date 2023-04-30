#include "../../../includes/minishell.h"

char	*get_env_value(const char *name, t_exec_context *exContext)
{
	char *result;
	int i;

	i = 0;
	if (name[i] == '{' && name[ft_strlen(name) - 1] == '}')
	{
		i++;
		result = ft_strdup(search_env_elem(exContext->env, ft_substr(name, i,
						ft_strlen(name) - i - 1))->content);
	}
	else
		result = ft_strdup(search_env_elem(exContext->env, name)->content);
	return (result);
}