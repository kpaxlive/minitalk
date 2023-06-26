# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/03/15 16:55:29 by fayan             #+#    #+#             #
#   Updated: 2022/03/15 16:55:37 by fayan            ###   ########.tr       #
#                                                                            #
# ************************************************************************** #

SERVER = server
CLIENT = client

SERVER_C = server.c
CLIENT_C = client.c

SERVER_O = $(server.c=.o)
CLIENT_O = $(client.c=.o)

HDR = ./minitalk.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER_O) $(CLIENT_O)
	$(MAKE) $(SERVER)
	$(MAKE) $(CLIENT)
%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_O) $(CLIENT_O) SERVER CLIENT

re: clean all

.PHONY: all clean re
