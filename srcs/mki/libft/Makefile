# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:30:00 by mki               #+#    #+#              #
#    Updated: 2021/03/09 16:19:34 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
.SUFFIXES = .c.o

PART = ft_atoi\
	   ft_bzero\
	   ft_calloc\
	   ft_isalnum\
	   ft_isalpha\
	   ft_isascii\
	   ft_isdigit\
	   ft_isprint\
	   ft_memccpy\
	   ft_memchr\
	   ft_memcmp\
	   ft_memcpy\
	   ft_memmove\
	   ft_memset\
	   ft_strchr\
	   ft_strdup\
	   ft_strlcat\
	   ft_strlcpy\
	   ft_strlen\
	   ft_strncmp\
	   ft_strnstr\
	   ft_strrchr\
	   ft_tolower\
	   ft_toupper\
	   ft_itoa\
	   ft_putchar_fd\
	   ft_putendl_fd\
	   ft_putnbr_fd\
	   ft_putstr_fd\
	   ft_split\
	   ft_strjoin\
	   ft_strmapi\
	   ft_strtrim\
	   ft_substr

BONUS = ft_lstadd_back\
		ft_lstadd_front\
		ft_lstclear\
		ft_lstdelone\
		ft_lstiter\
		ft_lstlast\
		ft_lstmap\
		ft_lstnew\
		ft_lstsize\
		ft_issep_bonus\
		ft_split_bonus\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(PART))) 
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS))) 
OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(PART))) 
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS))) 

.c.o: $(SRCS) $(SRCS_BONUS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

$(NAME): $(OBJS) $(OBJS_BONUS)
	$(AR) $@ $^
#	make clean

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: clean all bonus fclean re
