NAME := so_long

CC := cc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := game_logic/*.c
LIBRARY := -L minilibx-linux -l mlx -lXext -lX11
MINILIBX := minilibx-linux/

all:
	make -C $(MINILIBX)
	make -C libft
	$(CC) $(CFLAGS) $(SOURCE) libft/libft.a $(LIBRARY) -o $(NAME)

clean:
		make clean -C $(MINILIBX)
		make clean -C libft
		rm -rf *.o

fclean: clean
		make clean -C $(MINILIBX)
		make fclean -C libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
