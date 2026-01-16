NAME = push_swap

SRCS = main.c \
       stack_utils.c \
       input_val.c \
	   input_parsing.c \
	   operation_swap.c \
	   utils.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re