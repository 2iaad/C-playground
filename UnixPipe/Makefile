NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =  src/pipex.c \
        src/pipex_utils.c \
		libft_utils/ft_split.c \
		libft_utils/strings.c \

BONUS_SRCS =    src_bonus/pipex_bonus.c \
                src_bonus/pipex_bonus_utils.c \
				src_bonus/here_doc.c \
                get_next_line/get_next_line.c \
                get_next_line/get_next_line_utils.c \
				libft_utils/ft_split.c \
				libft_utils/strings.c \
				libft_utils/ft_strncmp.c \

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

ifeq ($(MAKECMDGOALS),bonus)

$(NAME) : $(OBJ_BONUS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c src_bonus/pipex_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

else
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c src/pipex.h
	$(CC) $(FLAGS) -c $< -o $@

endif

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY : clean