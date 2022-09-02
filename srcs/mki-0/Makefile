# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 16:29:32 by mki               #+#    #+#              #
#    Updated: 2021/03/11 16:15:56 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	gcc
42FLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	$(42FLAGS) -framework OpenGL -framework AppKit
AR			=	ar
ARFLAGS		=	rcs
RM			=	rm -rf

SRCS_F		=	bmp\
				cub3d\
				key\
				main\
				parsing_info_1\
				parsing_info_2\
				parsing_map_1\
				parsing_map_2\
				parsing_map_valid\
				parsing\
				pixel\
				raycasting\
				sprites_1\
				sprites_2\
				sprites_3\
				textures\
				wall

UTIS_F		=	ft_vector\
				ft_equation\
				get_next_line

SRCS_D		=	./sources/
UTIS_D		=	./utils/
INCS_D		=	./includes/

SRCS_C		=	$(addsuffix .c, $(addprefix $(SRCS_D), $(SRCS_F)))
SRCS_O		=	$(addsuffix .o, $(addprefix $(SRCS_D), $(SRCS_F)))
UTIS_C		=	$(addsuffix .c, $(addprefix $(UTIS_D), $(UTIS_F)))
UTIS_O		=	$(addsuffix .o, $(addprefix $(UTIS_D), $(UTIS_F)))

all:			$(NAME)

$(NAME):		$(SRCS_O) $(UTIS_O)
	make -C mlx_opengl
	make -C mlx_mms
	make -C libft
	cp mlx_opengl/libmlx.a .
	cp mlx_mms/libmlx.dylib .
	cp libft/libft.a .
	libtool -static libmlx.a libft.a -o cub3D.a
	$(AR) $(ARFLAGS) cub3d.a $^ 
	$(CC) $(CFLAGS) cub3d.a libmlx.dylib -o $@
	$(RM) cub3d.a libft.a libmlx.a
#	$(RM) $(SRCS_O) $(UTIS_O)

.c.o:	
	$(CC) $(42FLAGS) -c -o $@ $< -I $(INCS_D)

clean:
	$(RM) $(SRCS_O) $(UTIS_O)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
