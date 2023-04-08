
#include "../../../includes/minishell.h"

void	d_lstadd_back(t_doubly_lst **lst, t_doubly_lst *new)
{
	t_doubly_lst	*p;

	printf("%p", lst);
	if (!lst || !new)
		return ;
	p = *lst;
	if (*lst)
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->prev = p;
	}
	else
		*lst = new;
}
