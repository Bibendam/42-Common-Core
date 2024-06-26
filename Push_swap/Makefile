NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -f

SRCS = 	swap.c push.c rotate.c rev_rotate.c \
		sort_utils.c sort_5.c sort_big.c \
		errors.c error_utils.c utils.c ft_split.c \
		stacks.c index.c main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
