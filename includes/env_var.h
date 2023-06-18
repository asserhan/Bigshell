/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:56:39 by otait-ta          #+#    #+#             */
/*   Updated: 2023/06/18 22:56:40 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_H
# define ENV_VAR_H
/* Env Element : represent  variable as name value struct*/
typedef struct s_env_variable
{
	char					*name;
	char					*content;
	struct s_env_variable	*next;
	struct s_env_variable	*prev;
}							t_env_variable;

/* Env List: contain every variable as a node */
typedef struct s_env
{
	t_env_variable			*first;
	int						size;
	char					**env_array;
}							t_env;
/* convert env variables to a double linked list*/
t_env						*env_to_list(char **str);
/* Convert to string to env format "s1=s2"*/
char						*str_to_env_form(char *s1, char *s2);
/* add new env element to env list */
void						set_env_elem(t_env *env, t_env_variable *new_env);
/* print all env variables to the fd*/
void						print_env(t_env *env, int fd);
/* convert pair in form "s1=s2" to env element*/
t_env_variable				*create_env_elem(char *pair);
/* search an env element by the name and return it */
t_env_variable				*search_env_elem(t_env *env, char *name);
/* delete an env element from env list*/
void						delete_env_elem(t_env *list, t_env_variable *elem);
/*update an existing env element or creat new if not found*/
void						update_env_elem(t_env *env, char *name,
								char *new_content);
/* free all env variables*/
void						env_lstclear(t_env *env);

void						free_env(t_env **env);

char						**env_to_matrix(t_env_variable *head);

#endif
