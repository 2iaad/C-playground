# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 10:20:18 by ibouram           #+#    #+#              #
#    Updated: 2024/12/25 15:50:50 by ibouram          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	parsing/parsing.c parsing/utils.c  parsing/extract_data.c \
		parsing/read_map.c parsing/utils_split.c parsing/utils2.c parsing/utils3.c \
		parsing/parse_map.c parsing/parse_utils.c parsing/extract_helper.c \
		parsing/parse_file.c parsing/utils4.c \
		execution/execution.c execution/mouvement.c \
		execution/ray_cast.c execution/render.c  execution/texters.c\

SRC_UTILS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

RM = rm -rf

NAME = cub3D

CC = cc

SRCS = $(SRC:.c=.o)
SRCS_UTILS_OBJ = $(SRC_UTILS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS) $(SRCS_UTILS_OBJ)
	@$(CC) $(FLAGS) $^ .MLX/libmlx42.a -ldl -lglfw -lm -L"/Users/$(USER)/homebrew/Cellar/glfw/3.4/lib/" -o $@

$(SRCS) : %.o: %.c include/cub3d.h
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(SRCS_UTILS_OBJ) : %.o: %.c get_next_line/get_next_line.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(SRCS)
	@$(RM) $(SRCS_UTILS_OBJ)

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Clean"

re: fclean all