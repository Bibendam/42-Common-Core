CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a

SOURCES = server.c client.c
SOURCES_BONUS = server_bonus.c client_bonus.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(LIBFT_LIB) server client

bonus: $(LIBFT_LIB) server_bonus client_bonus

$(LIBFT_LIB):
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: server.o
	$(CC) $(CFLAGS) -o server server.o -L$(LIBFT) -lft

client: client.o
	$(CC) $(CFLAGS) -o client client.o -L$(LIBFT) -lft

server_bonus: server_bonus.o
	$(CC) $(CFLAGS) -o server_bonus server_bonus.o -L$(LIBFT) -lft

client_bonus: client_bonus.o
	$(CC) $(CFLAGS) -o client_bonus client_bonus.o -L$(LIBFT) -lft

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f server client server_bonus client_bonus
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus
