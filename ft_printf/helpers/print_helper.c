/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:56:47 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/07 12:19:26 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*putchar_count(char *s, char c, int *control)
{
	write(1, &c, 1);
	*control += 1;
	s++;
	return (s);
}

char	*put_str(char *s, char *arg, int *control)
{
	if (!arg)
	{
		s = put_str(s, "(null)", control);
		return (s);
	}
	while (*arg)
		arg = putchar_count(arg, *arg, control);
	s++;
	return (s);
}
