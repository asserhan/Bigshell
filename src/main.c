/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:32:00 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/11 13:57:53 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

int	main(int ac, char **av, char **env)
{
	char			*input;
	t_exec_context	exContext;

	input = NULL;
	if (init_data(&exContext, av, env))
		exit(1);
	while (ac)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		if (input)
			free(input);
		input = readline("minishell $ ");
		if (input && !*input)
		{
			d_lstclear(&exContext.cmds);
			continue ;
		}
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
		d_lstclear(&(exContext.cmds));
	}
	free_env(&(exContext.env));
	return (0);
}
