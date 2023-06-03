/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:58:32 by hasserao          #+#    #+#             */
/*   Updated: 2023/06/03 19:59:17 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_dup(t_exec_context *exContext)
{
    if (dup2(exContext->cmds->in, STDIN_FILENO) == -1)
        ft_msg_error("dup2", 1);
    if (dup2(exContext->cmds->out, STDOUT_FILENO) == -1)
        ft_msg_error("dup2", 1);
}