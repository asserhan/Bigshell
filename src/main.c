/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:32:00 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/09 10:05:53 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

int	main(int ac, char **av, char **env)
{
	t_exec_context	exContext;
	char			*input;

	(void)ac;
	if (init_data(&exContext, av, env))
		exit(1);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		input = readline("minishell $ ");
		if (!input)
			exit(g_exit_status);
		if (input[0] != '\0')
			add_history(input);
		if (pars_input(&exContext, input))
		{
			d_lstclear(&exContext.cmds);
			continue ;
		}
		execution(&exContext);
	}
	return (0);
}
