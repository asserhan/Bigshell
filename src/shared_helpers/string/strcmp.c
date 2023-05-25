/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str1cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:42:43 by otait-ta          #+#    #+#             */
/*   Updated: 2023/04/08 17:42:44 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(char *str1, char *str2)
{

	if (!str1 || !str2)
	{
		if (!str1 && !str2)
			return (0);
		else if (!str1)
			return (-1);
		else
			return (1);
	}
	while ((*str1 || *str2) && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
