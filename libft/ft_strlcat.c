/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:32:04 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:15 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		slen;
	size_t	dlen;
	int		rtn;
	int		i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	rtn = dlen + slen;
	if (dstsize <= dlen)
		rtn = dstsize + slen;
	else if (dstsize >= dlen)
	{
		while (src[i] != '\0' && dlen < dstsize - 1)
		{
			dst[dlen] = src[i];
			i++;
			dlen++;
		}
		dst[dlen] = '\0';
	}
	return (rtn);
}
