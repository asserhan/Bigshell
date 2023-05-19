/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:09:13 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/23 17:47:58 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len ;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(len + 1 * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		ft_strlcpy(p, s1, ft_strlen(s1) + 1);
		ft_strlcat(p, s2, len + 1);
	}
	return (p);
}
