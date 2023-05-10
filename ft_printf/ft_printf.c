/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:39:22 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/07 12:36:39 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	char	*s;
	va_list	args;
	int		control;

	control = 0;
	s = (char *)str;
	va_start(args, str);
	flag_anal(s, args, &control);
	va_end(args);
	return (control);
}

char	*flag_anal(char *s, va_list args, int *control)
{
	char	*temp;

	while (*s)
	{
		if (*s == '%' && !*(s + 1))
			break ;
		if (*s == '%')
		{
			temp = ++s;
			s = testing_flags(s, args, control);
			if (s == temp)
			{
				s = putchar_count(s, *s, control);
				continue ;
			}
		}
		else
			s = putchar_count(s, *s, control);
	}
	return (s);
}

char	*testing_flags(char *s, va_list args, int *control)
{
	if (*(s) == 'c')
		s = putchar_count(s, va_arg(args, int), control);
	else if (*(s) == 's')
		s = put_str(s, va_arg(args, char *), control);
	else if (*(s) == 'p')
		s = put_pointer(s,
				(unsigned long)va_arg(args, void *), control);
	else if (*(s) == 'd' || *(s) == 'i')
		s = put_dicimal(s, va_arg(args, int), control);
	else if (*(s) == 'u')
		s = put_dicimal(s, va_arg(args, unsigned int), control);
	else if (*(s) == 'x' || *(s) == 'X')
		s = put_hexa(s,
				(long long)va_arg(args, unsigned int), control);
	else if (*(s) == '%')
		s = putchar_count(s, '%', control);
	return (s);
}
