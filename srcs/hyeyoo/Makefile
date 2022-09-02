NAME = cub3D
SRCS = ${addprefix srcs/, ${shell ls ./srcs | grep '\.c'}}
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I./includes -I./libft/libft.h
DEBUG = -g
MLX_INC = -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit   # -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_INC = -L./libft -lft
MAKE = make

${NAME} : ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${DEBUG} ${MLX_INC} ${LIBFT_INC} -o ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} ${INC} ${DEBUG} -c $< -o $@

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

all : ${NAME}

re : fclean all


