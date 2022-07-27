# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbostan <hbostan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 13:05:33 by hbostan           #+#    #+#              #
#    Updated: 2022/07/25 13:05:43 by hbostan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAMESERVER = server
NAMECLIENT = client
SRCSERVER = server.c
SRCCLIENT = client.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
PRINTF = ./ft_printf/libftprintf.a
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

all: $(PRINTF) $(NAMESERVER) $(NAMECLIENT)

$(PRINTF):
	make -C ./ft_printf

$(NAMESERVER): $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(PRINTF)

$(NAMECLIENT): $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(PRINTF)

clean:
	make clean -C ./ft_printf
	rm -rf $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	make fclean -C ./ft_printf
	rm -rf $(NAMESERVER) $(NAMECLIENT)

.c:.o
	$(CC) $(FLAGS) -c $^ -o $@

re: fclean all

.PHONY: all clean fclean re