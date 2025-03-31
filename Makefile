# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 12:36:46 by melayoub          #+#    #+#              #
#    Updated: 2023/03/15 18:42:10 by melayoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME =
SERVER = server
CLIENT = client
# NAME_B =
SERVER_B = server_bonus
CLIENT_B = client_bonus

HEAD = minitalk.h
HEAD_B = minitalk_bonus.h

SRC_S = ./mandatory/server.c \
	./mandatory/minitools.c \

SRC_C = ./mandatory/client.c \
	./mandatory/minitools.c \

SRC_SB = ./bonus/server_bonus.c \
	./bonus/minitools_bonus.c \

SRC_CB = ./bonus/client_bonus.c \
	./bonus/minitools_bonus.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER): $(HEAD) $(SRC_S)
	$(CC) $(FLAGS) $(SRC_S) -o $(SERVER)

$(CLIENT): $(HEAD) $(SRC_C)
	$(CC) $(FLAGS) $(SRC_C) -o $(CLIENT)

$(SERVER_B): $(HEAD_B) $(SRC_SB)
	$(CC) $(FLAGS) $(SRC_SB) -o $(SERVER_B)

$(CLIENT_B): $(HEAD_B) $(SRC_CB)
	$(CC) $(FLAGS) $(SRC_CB) -o $(CLIENT_B)

clean:
	$(RM) $(SERVER) $(CLIENT) $(CLIENT_B) $(SERVER_B)

 fclean: clean

re: fclean all