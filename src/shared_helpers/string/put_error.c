#include "../../../includes/minishell.h"

extern int	g_exit_status;

void	put_error(char *message, char *param, int status_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(message, 2);
	if (param)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
	g_exit_status = status_code;
}
void	put_error_ex(char *message, char *param, char *suffix, int status_code)
{
	ft_putstr_fd(message, 2);
	if (param)
		ft_putstr_fd(param, 2);
	if (suffix)
		ft_putstr_fd(suffix, 2);
	g_exit_status = status_code;
}
void	ft_msg_error(char *message, int exit)
{
	perror(message);
	g_exit_status = exit;
}
