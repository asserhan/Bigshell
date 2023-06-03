/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:02:54 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/03 20:16:31 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	char_count(char *str)
{
	int		in_quote;
	char	quote_char;
	int		count;

	in_quote = 0;
	in_quote = '\0';
	count = 0;
	while (*str)
	{
		if ((*str == '\'' || *str == '\"') && !in_quote)
		{
			in_quote = 1;
			quote_char = *str++;
		}
		if (*str == quote_char && in_quote)
		{
			in_quote = 0;
			quote_char = '\0';
		}
		else
			count++;
		str++;
	}
	return (count);
}
char	*remove_quotes(char *str)
{
	int		i;
	char	*new_str;
	int		in_quote;
	char	quote_char;

	i = 0;
	in_quote = 0;
	new_str = ft_calloc(char_count(str) + 1, sizeof(char));
	while (*str)
	{
		if ((*str == '\'' || *str == '\"') && !in_quote)
		{
			in_quote = 1;
			quote_char = *str++;
		}
		if (*str == quote_char && in_quote)
		{
			in_quote = 0;
			quote_char = '\0';
		}
		else
			new_str[i++] = *str;
		str++;
	}
	return (new_str);
}

t_doubly_lst	*matrix_to_list(char **matrix)
{
	t_doubly_lst	*head;
	t_doubly_lst	*tail;
	t_doubly_lst	*node;
	char			*cmd;

	head = NULL;
	tail = NULL;
	while (*matrix)
	{
		cmd = ft_strdup(*matrix++);
		if (cmd && *cmd)
		{
			node = d_lstnew(cmd);
			if (!node)
				return (NULL);
			node->prev = tail;
			if (tail)
				tail->next = node;
			tail = node;
			if (!head)
				head = node;
		}
	}
	return (head);
}
