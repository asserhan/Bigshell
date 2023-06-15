/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:01:03 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/04 17:35:20 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	fill_line(int quotes, t_exec_context *exContext, char *delimiter, int *end)
{
	char	*line;
	char	*tmp;

	line = readline("> ");
	if (!line)
		return (-1);
	if (ft_strcmp(delimiter, line) == 0 && line[0])
	{
		free(line);
		line = NULL;
		return (1);
	}
	if (!quotes)
	{
		tmp = line;
		line = expand_token(line, exContext);
		if (line != tmp)
			free(tmp);
	}
	if (write(end[1], line, ft_strlen(line)) == -1)
		return (put_error("Error in readline\n", NULL, 0), 1);
	else if (write(end[1], "\n", 1) == -1)
		return (put_error("Error in readline\n", NULL, 0), 1);
	free(line);
	return (0);
}

void	boucle_file_line(int quotes, t_exec_context *exContext, char *delimiter,
		int *end)
{
	int	result;

	while (g_exit_status != 1)
	{
		result = fill_line(quotes, exContext, delimiter, end);
		if (result == -1)
		{
			if (quotes)
				free(delimiter);
			close(end[0]);
			close(end[1]);
			return ;
		}
		else if (result == 1)
			break ;
	}
	if (quotes)
		free(delimiter);
}
void	handle_heredoc(t_doubly_lst *old_list, t_doubly_lst *node,
		t_exec_context *exContext)
{
	int		end[2];
	char	*delimiter;
	int		quotes;

	signal(SIGINT, heredoc_sigint_handler);
	if (pipe(end) == -1)
		return (perror("pipe"));
	quotes = 0;
	if (ft_strchr(old_list->next->next->cmd, '\"'))
	{
		delimiter = remove_quotes(old_list->next->next->cmd);
		quotes = 1;
	}
	else
		delimiter = old_list->next->next->cmd;
	g_exit_status = 0;
	boucle_file_line(quotes, exContext, delimiter, end);
	node->in = end[0];
	add_fd(exContext, end[0]);
	add_fd(exContext, end[1]);
}
