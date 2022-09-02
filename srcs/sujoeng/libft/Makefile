LIBFT_PATH = ./srcs/
CC = gcc
NAME = libft.a
HEADERS = includes
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS)

SRCS = 	ft_bzero.c \
	ft_strlen.c \
	ft_isdigit.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_strjoin.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_putstr_fd.c \
	ft_strdel.c \
	ft_strnew.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	get_next_line.c

BMP =	./bmp/encode.c ./bmp/bitmap.c ./bmp/check.c ./bmp/header.c \
		./bmp/rgb_encode.c ./bmp/utils.c

LIBFT_FILES = $(addprefix $(LIBFT_PATH), $(SRCS))


OBJ = $(LIBFT_FILES:.c=.o)
OBJ_BMP = $(BMP:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_BMP)
			ar rc $(NAME) $(OBJ) $(OBJ_BMP)
			ranlib $(NAME)

clean:
			rm -f $(OBJ) $(OBJ_BMP)
fclean:	clean
			rm -f $(NAME)

re:		fclean all

.PHONY : all clean fclean re
