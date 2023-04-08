/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:33:30 by otait-ta          #+#    #+#             */
/*   Updated: 2023/04/08 01:47:22 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	ft_putstr_fd("inside", 1);
	if (lst)
	{
		p = lst;
		while (p->next)
		{
			f(p->content);
			p = p->next;
		}
		if (p->next == NULL)
			f(p->content);
	}
}
