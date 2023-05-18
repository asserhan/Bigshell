/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:36:58 by hasserao          #+#    #+#             */
/*   Updated: 2022/11/11 17:05:03 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	long int	z;

	z = n;
	if (z < 0)
	{
		ft_putchar('-', len);
		z = -z;
	}
	if (z < 10)
		ft_putchar(z + 48, len);
	else
	{
		ft_putnbr(z / 10, len);
		ft_putnbr(z % 10, len);
	}
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	if (n < 10)
		ft_putchar(n + 48, len);
	else
	{
		ft_putnbr_u(n / 10, len);
		ft_putnbr_u(n % 10, len);
	}
}

void	ft_putnbr_base(unsigned int n, char *base, int *len)
{
	if (n < 16)
		ft_putchar(base[n % 16], len);
	else
	{
		ft_putnbr_base(n / 16, base, len);
		ft_putnbr_base(n % 16, base, len);
	}
}
