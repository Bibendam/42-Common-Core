NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I../Libft
LDFLAGS = -L../Libft -lft
SRCS = pipex.c errors.c child.c free.c
OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS} ../Libft/libft.a
	${CC} ${OBJS} ${LDFLAGS} -o ${NAME}

../Libft/libft.a:
	make -C ../Libft

all: ${NAME}

clean:
	rm -f ${OBJS}
	make -C ../Libft clean

fclean: clean
	rm -f ${NAME}

re: fclean all
