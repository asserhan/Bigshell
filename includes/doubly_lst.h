#ifndef DOUBLY_LST_H
# define DOUBLY_LST_H

typedef struct s_doubly_lst
{
	void				*content;
	struct s_doubly_lst	*next;
	struct s_doubly_lst	*prev;
}						t_doubly_lst;

t_doubly_lst			*d_lstnew(void *content);

void	d_lstadd_front(t_doubly_lst **lst,
					t_doubly_lst *new_elm);

void	d_lstadd_back(t_doubly_lst **lst,
					t_doubly_lst *new_elm);

#endif