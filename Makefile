NAME = minitalk
CFLAGS = -Wall -Wextra -Werror
CC = cc

PRINTF = ft_printf/libftprintf.a

CLIENT = client
SERVER = server
CLIENT_B = client_bonus
SERVER_B = server_bonus

SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c
SRCS_SERVER_BONUS = server_bonus.c utils_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c utils_bonus.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(PRINTF) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(PRINTF) -o $(SERVER)

bonus: $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(PRINTF) -o $(SERVER_B)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(PRINTF) -o $(CLIENT_B)

clean:
	make clean -C ft_printf
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	make clean -C ft_printf
	rm -f $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)

re: fclean all

.PHONY: all clean fclean re bonus