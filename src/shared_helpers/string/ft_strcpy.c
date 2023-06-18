/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:36:22 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/11 11:38:20 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*p;

	p = dest;
	while (*src)
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}
