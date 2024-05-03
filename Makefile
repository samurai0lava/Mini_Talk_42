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
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(SERVER) $(CLIENT) $(LIB)

$(LIB):
	$(MAKE) -C libft/

$(CLIENT) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ src/client.o $(LIB)

$(SERVER) : $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ src/server.o $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_BONUS) : $(OBJS_BONUS) $(LIB)
	$(CC) $(CFLAGS) -o $@ bonus/client_bonus.o $(LIB)

$(SERVER_BONUS) : $(OBJS_BONUS) $(LIB)
	$(CC) $(CFLAGS) -o $@ bonus/server_bonus.o $(LIB)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) clean -C libft/

fclean: clean
	$(MAKE) fclean -C libft/
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
