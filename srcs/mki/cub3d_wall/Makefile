# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 16:29:32 by mki               #+#    #+#              #
#    Updated: 2021/02/04 15:49:19 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	gcc
CFLAGS		=	$(42FLAGS) -framework OpenGL -framework AppKit
42FLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	rcs
RM			=	rm -rf

SRCS_F		=	cub_check\
				cub3d\
				key\
				main\
				pixel\
				raycasting\
				textures\

UTIS_F		=	ft_vector\
				ft_equation\

SRCS_D		=	./sources/
UTIS_D		=	./utils/
INCS_D		=	./includes/

SRCS_C		=	$(addsuffix .c, $(addprefix $(SRCS_D), $(SRCS_F)))
SRCS_O		=	$(addsuffix .o, $(addprefix $(SRCS_D), $(SRCS_F)))
UTIS_C		=	$(addsuffix .c, $(addprefix $(UTIS_D), $(UTIS_F)))
UTIS_O		=	$(addsuffix .o, $(addprefix $(UTIS_D), $(UTIS_F)))

all:			$(NAME)

$(NAME):		$(SRCS_O) $(UTIS_O)
	make -C mlx
	make -C libft
	cp mlx/libmlx.a .
	cp libft/libft.a .
	libtool -static libmlx.a libft.a -o cub3D.a
	$(AR) $(ARFLAGS) cub3d.a $^ 
	$(CC) $(CFLAGS) cub3d.a -o $@
	$(RM) cub3d.a libft.a libmlx.a
	$(RM) $(SRCS_O) $(UTIS_O)

.c.o:	
	$(CC) $(42FLAGS) -c -o $@ $< -I $(INCS_D)

clean:
	$(RM) $(SRCS_O) $(UTIS_O)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re