NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -f

SRCS = swap.c push.c rotate.c rev_rotate.c sort_utils.c sort_small.c sort_big.c list_utils.c errors.c free.c index.c main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) -lm

clean:
	@${MAKE} -C libft fclean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
