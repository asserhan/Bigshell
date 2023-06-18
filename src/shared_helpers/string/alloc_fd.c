#include "../../../includes/minishell.h"

int	*alloc_fd(int fd)
{
	int	*fd_tab;

	fd_tab = malloc(sizeof(int));
	if (!fd_tab)
		return (0);
	*fd_tab = fd;
	return (fd_tab);
}

void	add_fd(t_exec_context *exContext, int fd)
{
	t_list	*fd_node;

	fd_node = ft_lstnew(alloc_fd(fd));
	ft_lstadd_back(&exContext->fds, fd_node);
}
