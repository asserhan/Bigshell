/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:11:11 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/25 14:18:22 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char const *set, char x)
{
	while (*set)
	{
		if (*set == x)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	else
	{
		i = 0;
		j = ft_strlen (s1) - 1;
		while (s1[i] && find_set(set, s1[i]))
				i++;
		while (s1[j] && find_set(set, s1[j]))
				j--;
		p = ft_substr(s1, i, (j - i) + 1);
	}
	return (p);
}
