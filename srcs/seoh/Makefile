# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 03:18:32 by seoh              #+#    #+#              #
#    Updated: 2020/10/25 03:42:09 by seoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	cub3D
LIBFT					=	libft.a
MINILIBX				=	libmlx.a
CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror -O3
RM						=	rm -f
INCLUDES_PATH			=	./includes/
LIBFT_PATH				=	./includes/libft/
MINILIBX_OPENGL			=	./includes/mlx/
INCS					=	-I${INCLUDES_PATH} -I${LIBFT_PATH} -I${MINILIBX_OPENGL}
INCLIB_OPENGL			=	-L${MINILIBX_OPENGL} -lmlx -framework OpenGL -framework Appkit \
							-L${LIBFT_PATH} -lft
SRCS					=	./srcs/main.c
OBJS					=	${SRCS:.c=.o}
.c.o:
							${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all: 						$(NAME)
${NAME}:					${OBJS}
							make  -C ${LIBFT_PATH}
							make -C ${MINILIBX_OPENGL}
							$(CC) $(CFLAGS) ${INCS} ${INCLIB_OPENGL} -o $(NAME) $(OBJS)
clean:
							$(MAKE) -C $(LIBFT_PATH) clean
							$(MAKE) -C $(MINILIBX_OPENGL) clean
							rm -f $(OBJS) $(MINILIBX)
fclean: 					clean
							$(MAKE) -C $(LIBFT_PATH) fclean
							rm -f $(NAME)
re: 						fclean all
.PHONY: 					all clean fclean re