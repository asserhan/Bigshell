NAME	=	libftprintf.a
HEADRS	=	ft_printf.h
AR		=	ar rc
CC		=	cc
FLAGS	= 	-Wall -Werror -Wextra 
RM		=	rm -rf

CFILES	= helpers/dicimal_helper.c helpers/hexa_helper.c helpers/print_helper.c ft_printf.c

OBJ = $(CFILES:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADRS)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
		$(RM) $(OBJ) 

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all  clean fclean re