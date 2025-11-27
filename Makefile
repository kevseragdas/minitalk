NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): server.c
	$(CC) $(CFLAGS) server.c -o $(NAME_SERVER)

$(NAME_CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o $(NAME_CLIENT)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean: clean

re: fclean all