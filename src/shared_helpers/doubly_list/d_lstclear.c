#include "../../../includes/minishell.h"

void	d_lstclear(t_doubly_lst **lst)
{
	t_doubly_lst *temp;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->args)
			free_matrix((*lst)->args);
		if ((*lst)->cmd)
			free((*lst)->cmd);
		temp = *lst;
		*lst = temp->next;
		free(temp);
	}
	*lst = NULL;
}