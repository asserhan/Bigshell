#include "../../../includes/minishell.h"

char	*get_env_value(char *name, t_exec_context *exContext)
{
	char *result;
	t_env_variable *match;

	result = NULL;
	match = search_env_elem(exContext->env, name);
	if (match)
		result = ft_strdup(search_env_elem(exContext->env, name)->content);
	return (result);
}