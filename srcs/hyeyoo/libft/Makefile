# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/30 19:18:23 by abenani           #+#    #+#              #
#    Updated: 2020/07/02 16:06:08 by hyeyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBH = libft.h
SRCS = ${shell ls . | grep '\.c'}
OBJS = ${SRCS:.c=.o}
CFLAG = -Wall -Wextra -Werror -g
RM = rm -f
CC = gcc
INC = -I./libft.h

all : ${NAME}

%.o : %.c
	${CC} $(CFLAG) ${INC} -c $< -o $@

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
clean:
	${RM} ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
