/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:23:35 by otait-ta          #+#    #+#             */
/*   Updated: 2023/05/18 16:24:03 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(va_list ap, char str, int *len)
{
	if (str == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (str == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (str == 'p')
		ft_print_address(va_arg(ap, long long), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (str == 'u')
		ft_putnbr_u(va_arg(ap, int), len);
	else if (str == 'x')
		ft_putnbr_base(va_arg(ap, int), "0123456789abcdef", len);
	else if (str == 'X')
		ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF", len);
	else if (str == '%')
		ft_putchar('%', len);
	else
		ft_putchar(str, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	if (write(1, 0, 0) == -1)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_print_str(ap, str[i + 1], &len);
			if (str[i + 1] != '\0')
				i++;
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}
