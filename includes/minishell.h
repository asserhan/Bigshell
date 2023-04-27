#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "./doubly_lst.h"
# include "./env_var.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

/* struct contain all cmnds in a linked list "cmds" and 
all env variables in other linked list "env"*/
typedef struct s_exec_context
{
	t_doubly_lst	*cmds;
	t_env			*env;
}					t_exec_context;

/* fill the execContext with initial data*/
int					init_data(t_exec_context *exContext, char **av,
						char **env_str);

/*---MATRIX---*/
/* iterate over a matrix and free every line */
void				free_matrix(char ***matrix);

/*--STRING--*/
/* 0 if equal 1 if not */
int					ft_strcmp(char *str1, char *str2);

/* Parsing*/
/* TODO*/
int					pars_input(t_exec_context *exContext, char *input);
char				**split_space(char *line);
#endif