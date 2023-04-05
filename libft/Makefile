# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:20:33 by otait-ta          #+#    #+#              #
#    Updated: 2022/10/24 11:20:46 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HEADRS	=	libft.h
AR		=	ar rc
CC		=	CC
FLAGS	= 	-Wall -Werror -Wextra 
RM		=	rm -rf

CFILES	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c \
	   		ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_strdup.c \
	   		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_isprint.c \
	   		ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
	   		ft_putnbr_fd.c ft_strtrim.c ft_memcpy.c ft_memmove.c ft_memset.c \
	   		ft_memcmp.c ft_memchr.c ft_bzero.c ft_calloc.c ft_striteri.c\

BONUS_CFILES  = ft_lstnew.c ft_lstadd_front.c  ft_lstsize.c ft_lstlast.c \
	   			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstadd_back.c ft_lstdelone.c \

OBJ = $(CFILES:.c=.o)

BONUS_OBJS = $(BONUS_CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADRS)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
		$(RM) $(OBJ) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

bonus: $(BONUS_OBJS)
		$(AR) $(NAME) $(BONUS_OBJS)

.PHONY: all bonus clean fclean re
