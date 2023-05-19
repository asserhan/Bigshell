#include "../../../includes/minishell.h"

extern int	exit_status;

void	put_error(char *message, char *param, int status_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	if (param)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
	exit_status = status_code;
}