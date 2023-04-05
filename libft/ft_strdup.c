/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:31:12 by otait-ta          #+#    #+#             */
/*   Updated: 2022/10/20 17:08:33 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*__p;
	int		i;

	i = 0;
	size = ft_strlen(s1) + 1;
	__p = malloc(size * sizeof(char));
	if (!__p)
		return (NULL);
	while (s1[i])
	{
		__p[i] = s1[i];
		i++;
	}
	__p[i] = '\0';
	return (__p);
}

// int main()
// {
//     char t[] = "io";
//     char *t1 = ft_strdup(t);
//     printf("%c",t1[1]);
// }