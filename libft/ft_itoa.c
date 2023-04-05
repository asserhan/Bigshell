/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:14:20 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/24 12:45:11 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_of_d(int nbr)
{
	int				rst;
	int				count;
	unsigned long	n;

	n = nbr;
	count = 0;
	rst = 1;
	if (nbr < 0)
	{
		n *= -1;
		count++;
	}
	while (rst > 0)
	{
		rst = n / 10;
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_nega(int n, char **rtr, int *limit, unsigned int *pnbr)
{
	if (n < 0)
	{
		*(rtr[0]) = '-';
		*pnbr = n * -1;
		*limit = 1;
	}
}

char	*ft_itoa(int n)
{
	int				size;
	int				i;
	int				limit;
	char			*rtr;
	unsigned int	pnbr;

	pnbr = n;
	i = 0;
	limit = 0;
	size = ft_n_of_d(n);
	rtr = (char *)malloc((size + 1) * sizeof(char));
	if (!rtr)
		return (NULL);
	ft_nega(n, &rtr, &limit, &pnbr);
	rtr[size--] = '\0';
	while (size >= limit)
	{
		rtr[size--] = 48 + (pnbr % 10);
		pnbr = pnbr / 10;
	}
	return (rtr);
}
