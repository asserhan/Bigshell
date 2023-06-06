#ifndef DOUBLY_LST_H
# define DOUBLY_LST_H
# include "env_var.h"
typedef struct s_doubly_lst
{
	char				*cmd;
	char				**args;
	int					in;
	int					out;
	struct s_doubly_lst	*next;
	struct s_doubly_lst	*prev;
}						t_doubly_lst;

t_doubly_lst			*d_lstnew(char *cmd);

void	d_lstadd_front(t_doubly_lst **lst,
					t_doubly_lst *new_elm);

void	d_lstadd_back(t_doubly_lst **lst,
					t_doubly_lst *new_elm);


int	d_lstsize(t_doubly_lst *lst);

	/* Transfer matrix to a doubly linked list */
	t_doubly_lst *matrix_to_list(char **matrix);

void					print_list(t_doubly_lst *head);

void					d_lstclear(t_doubly_lst **lst);

#endif
