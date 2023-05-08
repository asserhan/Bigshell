#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "./doubly_lst.h"
# include "./env_var.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>


/*---MACROS---*/
#define true 1
#define false 0
#define PATH_MAX                 1024   /* max bytes in pathname */

/* struct contain all cmnds in a linked list "cmds" and
all env variables in other linked list "env"*/
typedef struct s_exec_context
{
	t_doubly_lst	*cmds;
	t_env			*env;
	int 			infile;
	int				outfile;
	int				exit; //exit status
}					t_exec_context;

/*--- Redirections ---*/
typedef enum s_redir_t
{
	IN=0,
	OUT=1,
	APPEND=2,
	HERE_DOC=3,
	PIPE=4,
}		t_redir_t;

/* fill the execContext with initial data*/
int init_data(t_exec_context *exContext, char **av,
			  char **env_str);

/*---MATRIX---*/
/* iterate over a matrix and free every line */
void free_matrix(char ***matrix);
/* Counts the number of pointers in a `char **` array.
 Assumes that the array is terminated by a NULL pointer.*/
int count_matrix(char **arr);
/* Prints out the contents of an array `matrix`,
 * with each row separated by the string `separator`*/
void print_matrix(char **matrix,char separator);
/* add sub tokens to the end of final_tokens*/
char **matrix_push_back(char **matrix, char **back);
/*--STRING--*/
/* 0 if equal 1 if not */
int ft_strcmp(char *str1, char *str2);
/*Searches for the index of the first character in `str` that matches any character in `set`.*/
int find_char_index(const char *str, const char *set);

/* change the value of quote depanding on its place*/
void handle_quotes(int *s_quote, int *d_quote, char c);

////////////////////////////////////* Parsing*////////////////////////////////////

/* TODO */
void	ft_echo(char **arg);

/* TODO*/
int pars_input(t_exec_context *exContext, char *input);
/* split line given by new_line to multiple tokens*/
char **split_space(char *line);

/*takes a string 'str' and splits it into multiple tokens based on the provided delimiters*/
void line_to_tokens(char const *line, char *delimiters,
					char **tokens);
/* counts the number of words in a given string 'str' based on the provided 'delimiters'.*/
int words_number(const char *str, const char *delimiters);
/*splite all tokens given by split_space() to sub tokens taking expand in consideration */
char **split_tokens(char **tokens, t_exec_context *exContext);
/* checks if token have a $ if so it expnded if not it return the token  */
char *var_expand(char *token, t_exec_context *exContext);
/* checks if token have a ~ if so it expnded if not it return the token  */
char *path_expand(char *str, char *home);
/* * Retrieves the value of an environment variable by its name, from the
 * environment list stored in the execution context.
 * If the variable name is enclosed in curly braces, they will be removed before
 * searching for the variable.*/
char *get_env_value(char *name,
					t_exec_context *exContext);


#endif