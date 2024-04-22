NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -Iincludes

RM = rm -f

SRCS = small_sort.c utils.c utils2.c t_list.c radix_algo.c main.c ope1.c ope2.c ope3.c ope4.c ope_utils.c quicksort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C ../Libft
	@$(CC) $(CFLAGS) $(OBJS) ../Libft/libft.a -o $(NAME)

clean:
	@${MAKE} -C ../Libft fclean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
