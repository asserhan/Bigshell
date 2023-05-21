/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:31:01 by hasserao          #+#    #+#             */
/*   Updated: 2022/11/11 16:59:36 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write (1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr("(null)", len);
	while (s && s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_putnbr_address(unsigned long long n, int *len)
{
	char	*base ;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[n % 16], len);
	else
	{
		ft_putnbr_address(n / 16, len);
		ft_putnbr_address(n % 16, len);
	}
}

void	ft_print_address(unsigned long long n, int *len)
{
	ft_putstr("0x", len);
	if (n == 0)
		ft_putchar('0', len);
	else
		ft_putnbr_address(n, len);
}
