/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:55:46 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/20 17:08:33 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t_size;
	char	*__rtr;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	t_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	__rtr = malloc(t_size * sizeof(char));
	if (__rtr == NULL)
		return (NULL);
	while (s1[i])
	{
		__rtr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		__rtr[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	__rtr[ft_strlen(s1) + i] = '\0';
	return (__rtr);
}
