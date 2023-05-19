/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:17:13 by hasserao          #+#    #+#             */
/*   Updated: 2022/10/23 18:14:01 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	i;

	len_needle = ft_strlen (needle);
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	if ((len_needle == len) && ft_strncmp(haystack, needle, len) != 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		if ((haystack[i] == *needle) && (len - i >= len_needle)
			&& ft_strncmp(haystack + i, needle, len_needle) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
