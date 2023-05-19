/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:47 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/23 17:43:45 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	size ;

	size = ft_strlen(s1) + 1;
	p = (char *)malloc (size * sizeof(char));
	if (!p)
		return (NULL);
	else
		ft_memcpy(p, s1, size);
	return (p);
}
