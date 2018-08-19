# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mienache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 00:09:06 by mienache          #+#    #+#              #
#    Updated: 2017/01/02 00:09:10 by mienache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		= 	libft/libftprintf.a
NAME		= 	lemin.a
FILE		= 	lem-in
CC 			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	main.c
SRC_NAME 	= 	checker.c check_rooms.c ft_count.c lemin_tools.c validation.c \
				check_rooms.c ft_free.c solver_one.c solver_two.c \
				solver_three.c solver_four.c 

OBJ_NAME = $(SRC_NAME:.c=.o)
AR = ar rc
RLIB = ranlib
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC_NAME)
	$(AR) $(NAME) $(OBJ_NAME)
	$(RLIB) $(NAME)
	$(CC) $(CFLAGS) -o $(FILE) $(SRC) $(NAME) $(LIBFT) 

clean:
	$(RM) $(OBJ_NAME)
fclean: clean
	$(RM) $(NAME) $(FILE) 
re: fclean all