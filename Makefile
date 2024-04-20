CC = CC
CFLAGS = Werror Wextar Wall
NAME = client
NAME1 = server

SRCS = client.c server.c main.c utils.c



.SECONDARY:
.phony: all clean fclean
