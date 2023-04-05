/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:28:58 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/24 11:21:45 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	scape_space(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\v'
		|| str[*i] == '\r' || str[*i] == '\f' || str[*i] == '\n')
		(*i)++;
}

static void	signe(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	__rtr;
	long long	temp;

	__rtr = 0;
	sign = 1;
	i = 0;
	scape_space(str, &i);
	signe(str, &i, &sign);
	while (ft_isdigit(str[i]))
	{
		temp = __rtr;
		__rtr *= 10;
		if ((__rtr / 10) != temp)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		__rtr += str[i] - '0';
		i++;
	}
	return (__rtr * sign);
}
