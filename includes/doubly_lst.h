/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:45:52 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:54:44 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LST_H
# define DOUBLY_LST_H
# include "env_var.h"

typedef struct s_doubly_lst
{
	char				*cmd;
	char				**args;
	int					in;
	int					out;
	int					have_quotes;
	int					is_heredoc;
	struct s_doubly_lst	*next;
	struct s_doubly_lst	*prev;
}						t_doubly_lst;

t_doubly_lst			*d_lstnew(char *cmd);
void					d_lstadd_front(t_doubly_lst **lst,
							t_doubly_lst *new_elm);
void					d_lstadd_back(t_doubly_lst **lst,
							t_doubly_lst *new_elm);
int						d_lstsize(t_doubly_lst *lst);
t_doubly_lst			*matrix_to_list(char **matrix);
void					print_list(t_doubly_lst *head);
void					d_lstclear(t_doubly_lst **lst);
void					d_lstdelone(t_doubly_lst **head,
							t_doubly_lst *nodeToDelete);
t_doubly_lst			*d_lstlast(t_doubly_lst *lst);
#endif
