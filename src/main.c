/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:32:00 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/19 14:20:21 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			g_exit_status;

static int	get_input(char **input)
{
	*input = readline("minishell $ ");
	if (*input && !**input)
		return (1);
	if (!*input)
	{
		ft_printf("exit\n");
		exit(g_exit_status);
	}
	if (*input[0] != '\0')
		add_history(*input);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char			*input;
	t_exec_context	ex_context;
	t_doubly_lst	*head;

	input = NULL;
	if (init_data(&ex_context, av, env))
		exit(1);
	rl_catch_signals = 0;
	while (ac)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		if (input)
			free(input);
		if (get_input(&input))
			continue ;
		if (pars_input(&ex_context, input))
			continue ;
		head = ex_context.cmds;
		execution(&ex_context);
		d_lstclear(&head);
		ft_close_fd(&ex_context);
	}
	return (free_env(&(ex_context.env)), 0);
}
