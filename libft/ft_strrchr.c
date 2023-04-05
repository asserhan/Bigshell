/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:23:05 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/22 12:48:18 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s2;
	char	*temp;

	s2 = (char *)s;
	i = 0;
	c = (char)c;
	temp = 0;
	if (c == '\0')
	{
		while (s2[i])
			i++;
		return (s2 + i);
	}
	else
	{
		while (*s2)
		{
			if (*s2 == c)
				temp = s2;
			s2++;
		}
	}
	return (temp);
}
