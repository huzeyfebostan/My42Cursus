# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbostan <huzeyfebostan99@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 21:27:20 by hbostan           #+#    #+#              #
#    Updated: 2022/03/22 14:15:34 by hbostan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
INC = ft_printf.h
CFLAGS	= -Wall -Wextra -Werror
ARFLAGS	= -rsc
RM	= rm -rf
SRCS	= ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rsc $(NAME) $(OBJS)

%.o: %.c $(INC)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean
