/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dicimal_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:18:18 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/07 11:41:27 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*put_dicimal(char *s, long long nbr, int *control)
{
	char	table[18];
	int		i;

	i = 1;
	if (nbr == 0)
		putchar_count(s, '0', control);
	if (nbr < 0)
	{
		nbr = -nbr;
		putchar_count(s, '-', control);
	}
	while (nbr)
	{
		table[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i)
		putchar_count(s, table[i--], control);
	s++;
	return (s);
}
