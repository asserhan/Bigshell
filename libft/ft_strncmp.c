/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:34:46 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/23 18:11:32 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(unsigned char *)s1 || *(unsigned char *)s2) && i < n)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else
			if (*(unsigned char *)s1 < *(unsigned char *)s2)
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
