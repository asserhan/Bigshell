NAME = minishell
CC = cc
RM = rm -rf
LIBTFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
OBJ_DIR = obj
SRC := cd.c cd_utils.c echo.c env.c exit.c export.c export_utils.c pwd.c unset.c exec.c exec_builtins.c exec_utils.c files.c process.c main.c check_syntax.c conver_list_forma.c crud_env.c \
		delete_env.c env_to_matrix.c env_utils.c get_env_value.c sort_env.c handel_heredoc.c handel_redirection.c herdoc_cases.c initialization.c \
		line_to_tokens.c matrix_to_list.c pars_input.c path_expend.c signals.c split_space.c split_tokens.c subtoken.c var_expand.c d_lstadd_back.c d_lstadd_front.c \
		d_lstclear.c d_lstdelone.c d_lstlast.c d_lstnew.c d_lstsize.c print_list.c count_matrix.c free_matrix.c last_element_matrix.c matrix_add_front.c matrix_concat.c \
		matrix_push_back.c print_matrix.c alloc_fd.c check_string.c find_char_index.c ft_strcat.c ft_strcpy.c ft_strpbrk.c put_error.c strcmp.c
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
RL = -L/goinfre/hasserao/homebrew/opt/readline/lib -lreadline -I/goinfre/hasserao/homebrew/opt/readline/include \
	-L/goinfre/otait-ta/homebrew/opt/readline/lib -lreadline -I/goinfre/otait-ta/homebrew/opt/readline/include  -Qunused-arguments
HEAD = ./includes/minishell.h
FLAGS = -Wall -Werror -Wextra  

all: $(NAME) 
$(NAME):  $(OBJ) obj_libft obj_printf 
	@$(CC)  $(FLAGS) $(RL) $(OBJ) $(LIBTFT) $(PRINTF)  -o $@

$(OBJ_DIR)/%.o: src/%.c $(HEAD)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(RL) -c $< -o $@

$(OBJ_DIR)/%.o: src/*/%.c $(HEAD)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(RL) -c $< -o $@ 

$(OBJ_DIR)/%.o: src/*/*/%.c $(HEAD)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(RL) -c $< -o $@

obj_libft:
	@$(MAKE) -C libft
	@make bonus -C libft

obj_printf:
	$(MAKE) -C ft_printf

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re obj_libft
