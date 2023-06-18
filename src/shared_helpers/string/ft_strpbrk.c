/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:26:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/22 14:27:40 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_strpbrk(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return (0);
			i++;
		}
		s1++;
	}
	return (1);
}
