/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:09:15 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/24 13:18:38 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	long	nb;

	nb = n;
	length = n_len(n);
	str = (char *)malloc(length + 1 * sizeof (char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		return (str[0] = '0', str);
	while (nb != 0)
	{
		str[--length] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
