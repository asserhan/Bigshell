/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:34:07 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/16 19:42:24 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <sys/ioctl.h>

void	sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
	g_exit_status = 1;
  	rl_on_new_line(); 
    rl_replace_line("", 0); 
	write(1, "\n", 1);
    rl_redisplay();	
	}
}
void	sigquit_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		g_exit_status = 131;
    rl_replace_line("", 0); 
	write(1,"Quit: 3\n", 9);
	rl_redisplay();
	}
}
void	heredoc_sigint_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}
