CC = cc
CFLAGS = -Werror -Wextra -Wall
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
LIB = libft/libft.a

SRC_BONUS = bonus/server_bonus.c bonus/client_bonus.c
SRCS = src/server.c src/client.c
OBJS = $(SRCS:.c=.o)
ONJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(SERVER) $(CLIENT) $(LIB)

$(LIB):
	make -C libft/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT) : client.o $(LIB)
	$(CC) $@ -o client.o $(LIB)

$(SERVER) : $(OBJS) $(LIB)
	$(CC) $@ -o server.o $(LIB)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_BONUS) : client_bonus.o $(LIB)
	$(CC) $(CFLAGS) -o $@ client_bonus.o $(LIB)

$(SERVER_BONUS) : server_bonus.o $(LIB)
	$(CC) $(CFLAGS) -o $@ server_bonus.o $(LIB)

clean:
	@rm -f $(OBJS)
	$(MAKE) clean -C libft/

fclean: clean
	$(MAKE) fclean -C libft/
	@rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
