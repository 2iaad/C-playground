NAME = push_swap

NAME_BONUS = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS =	Mandatory/main.c \
		Mandatory/parser.c \
		Mandatory/sorter.c \
		Mandatory/instructions.c \
		Mandatory/instructions_helper.c \

SRCS_BONUS =	Bonus/main_bonus.c \
				Bonus/instructions_bonus.c \
				Bonus/parser_bonus.c \
				Bonus/instructions_helper_bonus.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

UTILS =		utils/ft_split.c \
			utils/libft_utils.c \
			utils/linked_list_utils.c \
			utils/utils_helper.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJ_UTILS = $(UTILS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(OBJ_UTILS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c Mandatory/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME_BONUS) : $(OBJS_BONUS) $(OBJ_UTILS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c Bonus/push_swap_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_UTILS): %.o: %.c utils/utils.h
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS) $(OBJ_UTILS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all