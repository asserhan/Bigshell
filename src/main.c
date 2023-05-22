/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:32:00 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/22 01:51:11 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_status;

int	main(int ac, char **av, char **env)
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
			continue ;
		// while (exContext.cmds->args[i])
		// {
		// 	printf("%s\n", exContext.cmds->args[i]);
		// 	i++;
		// }
		exec_builtins(&exContext);
	}
	return (0);
}
