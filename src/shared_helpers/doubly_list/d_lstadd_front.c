

#include "../../../includes/minishell.h"

void	d_lstadd_front(t_doubly_lst **lst, t_doubly_lst *new)
{
	if (lst && new)
	{
		new->next = *lst;
		new->prev = NULL;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
	}
}
