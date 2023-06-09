# Variables
NAME = minishell
CC = cc
#FLAGS = -Wall -Werror -Wextra -g -I ~/.brew/opt/readline/include -I /usr/local/opt/readline/include
RM = rm -rf
LIBTFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
OBJ_DIR = obj
SRC := $(notdir $(shell find src -name '*.c'))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LEAKS =  -g
rlpath = $(shell brew --prefix readline)
RL = -L$(rlpath)/lib -lreadline -I$(rlpath)/include
FLAGS = -Wall -Werror -Wextra -Qunused-arguments   $(RL)  
# Targets
all: $(NAME)

$(NAME): $(OBJ) obj_libft obj_printf
	@$(CC)  $(FLAGS) $(OBJ) $(LIBTFT) $(PRINTF)  -lreadline -o $@

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(LEAKS) -c $< -o $@

$(OBJ_DIR)/%.o: src/*/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/*/*/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

obj_libft:
	$(MAKE) -C libft
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
