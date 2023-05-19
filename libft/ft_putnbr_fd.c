/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:07:28 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/25 16:49:02 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	z;

	z = n;
	if (z < 0)
	{
		ft_putchar_fd('-', fd);
		z = -z;
	}
	if (z < 10)
	{
		ft_putchar_fd(z + 48, fd);
	}
	else
	{
		ft_putnbr_fd(z / 10, fd);
		ft_putnbr_fd(z % 10, fd);
	}
}
