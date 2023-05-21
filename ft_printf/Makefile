SRC =	ft_printf.c ft_putnbrs.c ft_printf_utils.c
OBJ	= $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
CC = cc 
RM = rm -f 

%.o: %c 
	$(CC)  $(CFLAGS) -c $<

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
                                                
all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean