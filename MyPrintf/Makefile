# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 20:37:45 by zderfouf          #+#    #+#              #
#    Updated: 2023/12/12 19:08:10 by zderfouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

AR = ar rc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthexa.c ft_putadress.c \
	ft_putunbr.c ft_printf.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)


%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

$(NAME) : $(OBJ)
	$(AR) $@ $^

fclean: clean
	rm -f $(NAME)

re : fclean all