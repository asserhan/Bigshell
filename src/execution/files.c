/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:58:32 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/06 20:48:09 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_dup(t_exec_context *exContext)
{
	if (exContext->cmds->in != STDIN_FILENO)
	{
		if (dup2(exContext->cmds->in, STDIN_FILENO) == -1)
			ft_msg_error("dup2", 1);
	}
    if(exContext->cmds->out != STDOUT_FILENO)
    {
        if (dup2(exContext->cmds->out, STDOUT_FILENO) == -1)
            ft_msg_error("dup2", 1);
    }
}
void	ft_close_fd(t_exec_context *exContext)
{
    t_exec_context *tmp;

    tmp = exContext;
    while (tmp->cmds)
    {
        if (tmp->cmds->in != STDIN_FILENO)
        {
            if (close(tmp->cmds->in) == -1)
                ft_msg_error("close", 1);
        }
         if (tmp->cmds->out != STDOUT_FILENO)
        {
            if (close(tmp->cmds->in) == -1)
                ft_msg_error("close", 1);
        }
       
        tmp->cmds = tmp->cmds->next;
    }
}