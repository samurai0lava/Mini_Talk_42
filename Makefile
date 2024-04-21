CC = CC
CFLAGS = Werror Wextar Wall
CLIENT = client
SERVER = server
LIB = libft.a

OBJS = $(SRCS:.c=.o)


all: $(SERVER) $(CLIENT) $(LIB)

$(LIB):
	$(MAKE) -C libft

$(CLIENT): client.o utils.o
	$(CC) $(CFLAGS) client.o utils.o $(LIB)

$(SERVER): $(OBJS)
	$(CC) $(CFLAGS) server.o utils.o $(LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f client.o server.o utils.o

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

re: fclean all

.SECONDARY: client.o server.o utils.o
.phony: all clean fclean
