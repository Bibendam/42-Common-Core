NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = pipex.c errors.c child.c free.c

OBJS = ${SRCS:.c=.o}

${NAME}:
		make all -C libft
		gcc $(CFLAGS) $(SRCS) -o $(NAME)

all:	${NAME}

bonus: all

clean:
		rm -f ${OBJS}
		make clean -C libft

fclean: clean;
		rm -f ${NAME}
		make fclean -C libft

re:	fclean all
