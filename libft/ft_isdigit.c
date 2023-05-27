/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:51:47 by hasserao          #+#    #+#             */
/*   Updated: 2023/05/27 17:28:40 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
int  is_space( int c)
{
	return (c == ' ');
}

int parse_arg(char *str)
{

	int i;
	int digit_count;
	i = 0;
	digit_count = 0;
	while (is_space(str[i]))
		i++;
	if(str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		digit_count++;
		i++;
	}
	while (is_space(str[i]))
		i++;
	return (str[i] == '\0' && digit_count) ? 1 : 0;
	
}
