/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:15:09 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/20 17:08:33 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*__s1;
	unsigned char		*__s2;
	size_t				i;

	i = 0;
	__s1 = ((unsigned char *)s1);
	__s2 = ((unsigned char *)s2);
	while (i < n)
	{
		if (*__s1 == *__s2)
		{
			__s1++;
			__s2++;
			i++;
			continue ;
		}
		else
			return (*__s1 - *__s2);
	}
	return (0);
}
