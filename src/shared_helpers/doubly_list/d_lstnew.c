
#include "../../../includes/minishell.h"

t_doubly_lst	*d_lstnew(void *content)
{
	t_doubly_lst	*rtr;

	rtr = malloc(sizeof(t_doubly_lst));
	if (!rtr)
		return (NULL);
	rtr->content = content;
	rtr->next = NULL;
	rtr->prev = NULL;
	return (rtr);
}
