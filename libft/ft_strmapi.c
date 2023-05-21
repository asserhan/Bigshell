/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:28:28 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/25 15:34:57 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	if (!s || !f)
		return (NULL);
	p = ft_strdup(s);
	if (!p)
		return (NULL);
	else
	{
		i = 0;
		while (s[i])
		{
			p[i] = f(i, s[i]);
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
