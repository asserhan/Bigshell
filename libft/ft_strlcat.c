/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:41:29 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/25 13:54:30 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	l_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0 && !dst)
		return (l_src);
	l_dst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= l_dst)
		return (l_src + dstsize);
	while (src[i] && (i + l_dst) < dstsize - 1)
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}
