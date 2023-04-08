
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
/* convert pair in form "s1=s2" to env element*/
t_env_variable				*str_to_env_elem(char *pair);
/* add new env element to env list */
void						set_env_elem(t_env *env, t_env_variable *new_env);
/* print all env variables to the fd*/
void						print_env(t_env *env, int fd);
#endif