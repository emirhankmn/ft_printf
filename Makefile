# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 13:42:59 by eakman            #+#    #+#              #
#    Updated: 2023/07/31 20:56:04 by eakman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CFLAGS		=	-Wall -Werror -Wextra
SRC			=	ft_printf.c ft_printf_utils.c 
CC			=	gcc
AR			=	ar rcs
RM			=	rm -rf
OBJ			=	$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
