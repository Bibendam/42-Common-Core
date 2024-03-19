NAME = libftprintf.a

LIBFTNAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFTDIR = ../Libft

SRCS = ft_printf.c ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_print_utils.c

OBJS = ${SRCS:.c=.o}

all:	${NAME}

makelibft:
		make -C ${LIBFTDIR}
		cp ${LIBFTDIR}/${LIBFTNAME} .
		mv ${LIBFTNAME} ${NAME}

${NAME}: makelibft ${OBJS}
		ar -r ${NAME} ${OBJS}

bonus: all

clean:
		rm -f ${OBJS}
		cd ${LIBFTDIR} && make clean

fclean: clean;
		rm -f ${NAME}
		cd ${LIBFTDIR} && make fclean

re:	fclean all
