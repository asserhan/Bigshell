# Variables
NAME = minishell
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBTFT = libft/libft.a
EXEC_DIR = src/execution
PARS_DIR = src/parsing
OBJ_DIR = obj
SRC := $(notdir $(wildcard $(EXEC_DIR)/*.c $(PARS_DIR)/*.c src/*.c))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Targets
all: $(NAME)

$(NAME): $(OBJ) obj_libft
	@$(CC) $(FLAGS) $(OBJ) $(LIBTFT) -o $@

$(OBJ_DIR)/%.o: $(EXEC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@


obj_libft:
	$(MAKE) -C libft
	@make bonus -C libft

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re obj_libft