/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:32:00 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/09 16:41:24 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_status;

int	main(int ac, char  **av, char **env)
{
	t_exec_context	exContext;
	char			*input;

	(void)ac;
	if (init_data(&exContext, av, env))
		exit(1);
	while (1)
	{
		input = readline("minishell $ ");
		if (!*input || pars_input(&exContext, input))
			continue;
		
	}
	return (0);
}

