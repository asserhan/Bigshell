# Variables
CC		=	cc
FLAGS	= 	-Wall -Werror -Wextra 
RM		=	rm -rf
LIBTFT 	= 	libft/libft.a
EXEC_DIR = 	src/execution
PARS_DIR = 	src/parsing
OBJ_DIR = 	obj

SRC = $(wildcard $(EXEC_DIR)/*.c $(PARS_DIR)/*.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all:
	@mkdir  $(OBJ_DIR)
	@cd libft && make

$(OBJ_DIR)/%.o: $(EXEC_DIR)/%.c $(PARS_DIR)/%.c
	@$(CC)  $(FLAGS)  -c $< -o $@


clean:
		cd libft && make clean

fclean: clean
		cd libft && make fclean

re: fclean all

.PHONY: all clean fclean  re