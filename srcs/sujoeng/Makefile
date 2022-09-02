SRCS_PATH = ./srcs/
HEADERS = ./includes/
LIBFT_HEADERS = ./libft/includes/

SRCS_FILES = cub3d_start.c \
			 draw_sprite.c \
			 draw_texture.c \
			 error.c \
			 ft_tools.c \
			 key_events.c \
			 main.c \
			 map_check.c \
			 map_parse.c \
			 map_set.c \
			 move_rotation.c \
			 move.c \
			 pos_dir_init.c \
			 raycasting.c \
			 sky_floor.c \
			 space_check.c \
			 sprite.c \
			 texture_init.c
			 
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)
BMP = screenshot.bmp
LIB = libft/libft.a
MLX_MAC =  -lmlx -framework OpenGL -framework AppKit
NAME = cub3D
CC = gcc
FLAGS = -Werror -Wall -Wextra -I $(HEADERS) -I $(LIBFT_HEADERS)

all: $(NAME)

$(NAME): $(OBJS) $(LIB) $(MLX)
		$(CC) $(FLAGS) $(OBJS) $(MLX_MAC)  -o $(NAME) $(LIB)

$(LIB):
	make -j4 -C ./libft

$(MLX):
	make -j4 -C ./minilibx

clean:
	make fclean -C ./libft
	rm -f $(OBJS) $(BMP)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
