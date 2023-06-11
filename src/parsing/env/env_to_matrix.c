/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:46:35 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/11 10:52:30 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**env_to_matrix(t_env_variable *head)
{
	int				count;
	t_env_variable	*current;
	char			**result;
	int				i;
	int				nameLength;
	int				contentLength;

	if (head == NULL)
		return (NULL);
	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	current = head;
	i = 0;
	while (current != NULL)
	{
		nameLength = strlen(current->name);
		contentLength = strlen(current->content);
		result[i] = (char *)malloc((nameLength + contentLength + 2)
				* sizeof(char));
		if (result[i] == NULL)
		{
			while (i > 0)
			{
				i--;
				free(result[i]);
			}
			free(result);
			return (NULL);
		}
		ft_strcpy(result[i], current->name);
		ft_strcat(result[i], "=");
		ft_strcat(result[i], current->content);
		i++;
		current = current->next;
	}
	result[count] = NULL;
	return (result);
}
