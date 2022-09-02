# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 16:29:32 by mki               #+#    #+#              #
#    Updated: 2021/01/18 11:16:05 by mki              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CC			=	gcc
CFLAGS		=	$(42FLAGS) -framework OpenGL -framework AppKit
42FLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	rcs
RM			=	rm -rf

SRCS_F		=	ft_cub3d_init\
				ft_cub3d_loop\
				ft_cub3d_screen\
				ft_cub3d\
				ft_draw_vec\
				ft_draw_line\
				ft_draw_map\
				ft_draw_player\
				ft_key_move\
				ft_key_rotate\
				ft_key\

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
	cp mlx/libmlx.a cub3D.a
	$(AR) $(ARFLAGS) cub3D.a $^
	$(CC) $(CFLAGS) cub3D.a -o cub3D
	$(RM) cub3D.a
	$(RM) $(SRCS_O) $(UTIS_O)
	./cub3D

.c.o:	
	$(CC) $(42FLAGS) -c -o $@ $< -I $(INCS_D)

clean:
	$(RM) $(SRCS_O) $(UTIS_O)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re