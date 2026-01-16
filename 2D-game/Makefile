NAME = so_long

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -Imlx

FLAGS = -lmlx -framework OpenGL -framework AppKit 

SRCS =	main.c \
		utils.c \
		parsing.c \
		path_check.c \
		mlx.c \
		player_moves.c \

SRCS_UTILS =	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

SRC_OBJ = $(SRCS:.c=.o)
SRC_UTILS_OBJ = $(SRCS_UTILS:.c=.o)

all : $(NAME)

$(NAME) : $(SRC_OBJ) $(SRC_UTILS_OBJ)
	$(CC) $(FLAGS) $^ -o $@

$(SRC_OBJ): %.o : %.c so_long.h
			$(CC) $(CFLAGS) -c $< -o $@

$(SRC_UTILS_OBJ): %.o : %.c get_next_line/get_next_line.h
				  $(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(SRC_OBJ)
	$(RM) $(SRC_UTILS_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all