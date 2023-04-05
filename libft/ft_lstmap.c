/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:06:55 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/24 11:22:17 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nd;
	t_list	*n_list;

	n_list = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			nd = ft_lstnew(f(lst->content));
			if (!nd)
			{
				ft_lstclear(&n_list, del);
				return (NULL);
			}
			ft_lstadd_back(&n_list, nd);
			lst = lst->next;
		}
	}
	return (n_list);
}
