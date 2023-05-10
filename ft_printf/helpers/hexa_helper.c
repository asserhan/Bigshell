/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:45:29 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/07 12:23:24 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*put_pointer(char *s, unsigned long pointer, int *control)
{
	char	table[18];
	int		i;
	char	*num;

	num = "0123456789abcdef";
	i = 1;
	if (!pointer)
	{
		s = put_str(s, "0x0", control);
		return (s);
	}
	while (pointer)
	{
		table[i++] = num[pointer % 16];
		pointer /= 16;
	}
	if (--i)
		put_str(s, "0x", control);
	while (i)
	{
		putchar_count(s, table[i--], control);
	}
	s++;
	return (s);
}

char	*put_hexa(char *s, long long nbr, int *control)
{
	char	table[18];
	int		i;
	char	*num;

	if (nbr == 0)
	{
		s = put_str(s, "0", control);
		return (s);
	}
	if (*s == 'x')
		num = "0123456789abcdef";
	else
		num = "0123456789ABCDEF";
	i = 1;
	while (nbr)
	{
		table[i++] = num[nbr % 16];
		nbr /= 16;
	}
	i--;
	while (i)
		putchar_count(s, table[i--], control);
	s++;
	return (s);
}
