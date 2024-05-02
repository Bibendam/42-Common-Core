NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -f

SRCS = utils.c utils2.c utils3.c t_list.c main.c ope1.c ope2.c ope3.c ope4.c ope_utils.c quicksort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:
	@${MAKE} -C libft fclean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
