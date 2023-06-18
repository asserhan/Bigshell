/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:46:35 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/12 18:49:04 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	convert(t_env_variable **current, char **result, int *i)
{
	int	name_length;
	int	content_length;

	name_length = ft_strlen((*current)->name);
	content_length = ft_strlen((*current)->content);
	result[*i] = (char *)malloc((name_length + content_length + 2)
			* sizeof(char));
	if (result[*i] == NULL)
	{
		while (*i > 0)
		{
			*i = *i - 1;
			free(result[*i]);
		}
		free(result);
		return (1);
	}
	ft_strcpy(result[*i], (*current)->name);
	ft_strcat(result[*i], "=");
	ft_strcat(result[*i], (*current)->content);
	*i = *i + 1;
	(*current) = (*current)->next;
	return (0);
}

int	list_size(t_env_variable *head)
{
	int				count;
	t_env_variable	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

char	**env_to_matrix(t_env_variable *head)
{
	int				count;
	t_env_variable	*current;
	char			**result;
	int				i;

	if (head == NULL)
		return (NULL);
	count = list_size(head);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	current = head;
	i = 0;
	while (current != NULL)
	{
		if (convert(&current, result, &i))
			return (NULL);
	}
	result[count] = NULL;
	return (result);
}
