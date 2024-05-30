NAME		=	so_long

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -lX11

MLX			=   -L ./ -lmlx -lXext -lX11

LIB_FLAGS	=	-L ./ -lft

INCLUDE		=	-I ./includes

MAP =		map.c

WINDOW =	display.c

A_SRC =		endgame.c images.c main.c 

SRC =		$(MAP) $(WINDOW) $(A_SRC)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -O2 -c $< -o $(<:%.c=%.o)

$(NAME): $(OBJ)
	del /Q $(NAME)
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(MLX) -o $(NAME)

clean:
	del /Q $(OBJ)
	del /Q ./a.out
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all bonus clean fclean re