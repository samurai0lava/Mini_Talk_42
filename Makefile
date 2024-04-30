CC = cc
CFLAGS = -Werror -Wextra -Wall
CLIENT = client
SERVER = server
LIB = libft/libft.a

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

all: $(SERVER) $(CLIENT) $(LIB)

$(LIB):
	$(MAKE) -C libft/

$(CLIENT): client.o $(LIB)
	$(CC) $(CFLAGS) -o $@ client.o $(LIB)

$(SERVER): server.o $(LIB)
	$(CC) $(CFLAGS) -o $@ server.o $(LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	$(MAKE) clean -C libft/

fclean: clean
	$(MAKE) fclean -C libft/
	@rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
