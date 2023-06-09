/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:34:07 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/09 09:26:24 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <sys/ioctl.h>

int		g_exit_status;

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
void	heredoc_sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		// rl_replace_line("", 0);
		// rl_on_new_line();
	}
}
void	sigquit_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		g_exit_status = 131;
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
