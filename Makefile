# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 20:53:55 by emsoares          #+#    #+#              #
#    Updated: 2023/01/09 09:28:50 by emsoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

CLIENT = client
SERVER = server

SRC_C = client.c
OBJ_C = $(SRC_C:%.c=%.o)

SRC_S = server.c
OBJ_S = $(SRC_S:%.c=%.o)

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

BONUS_C = client_bonus.c
BONUS_OBJ_C = $(BONUS_C:%.c=%.o)

BONUS_S = server_bonus.c
BONUS_OBJ_S = $(BONUS_S:%.c=%.o)

all: $(NAME)

$(LIBFT):
	make all -C ./libft

$(NAME): $(OBJ_C) $(OBJ_S) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(SERVER)
	@$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(CLIENT)

bonus: $(BONUS_OBJ_S) $(BONUS_OBJ_C) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJ_S) $(LIBFT) -o $(SERVER_BONUS)
	@$(CC) $(CFLAGS) $(BONUS_OBJ_C) $(LIBFT) -o $(CLIENT_BONUS)

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJ_S) $(OBJ_C)
	@$(RM) $(BONUS_OBJ_S) $(BONUS_OBJ_C)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all