# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 03:23:34 by seoh              #+#    #+#              #
#    Updated: 2020/02/29 08:39:33 by seoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc -c $(CFLAGS) -c $< -o $@

$(NAME): ${OBJS}
		ar rcs $@ ${OBJS}

all : $(NAME)

clean:
	rm -f *.o
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re : fclean all
