/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:32:00 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/01 14:56:50 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char const **av, char **env)
{
	t_exec_context	exContext;
	char			*input;

	(void)ac;
	if (init_data(&exContext, (char **)av, env))
		exit(1);
	print_env(exContext.env, 1);
	while (1)
	{
		input = readline("minishell $ ");
		if (!input)
		{
			printf("exit\n");
			return (1);
		}
		pars_input(&exContext, input);
	}
	return (0);
}

