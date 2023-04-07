
#ifndef ENV_VAR_H
# define ENV_VAR_H
/* Env Element : represent  variable as name value struct*/
typedef struct s_env_variable
{
	char					*name;
	char					*value;
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

#endif