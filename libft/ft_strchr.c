/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:56:52 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/24 16:28:51 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;
	char	c2;

	s2 = (char *)s;
	i = 0;
	c2 = (char)c;
	if (c2 == '\0')
	{
		while (s2[i])
			i++;
		return (s2 + i);
	}
	else
		while (*s2 != c2 && *s2)
			s2++;
	if (!*s2)
		return (NULL);
	return (s2);
}
