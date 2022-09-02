/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:08:43 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:59:39 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "setting.h"
#include "vector.h"
#include "color.h"
#include "image.h"
#include "key.h"
#include "sprite.h"
#include "common.h"
#include "map.h"
#include "error.h"
#include "info.h"
#include "texture.h"
#include <mlx.h>
#include <stdlib.h>
#include "bmp.h"
#include "libft.h"
#define MOVE_SPEED 1
#define ROT_SPEED 0.1

/*
	description: a hook for exiting program
*/
int		exit_hook(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img.img);
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
	return (0);
}

/*
	description:
		process key press
*/
int		key_press(int key_code, t_info *info)
{
	int					sign;
	t_vector			rotated;

	if (key_code == KEY_LEFT_ARROW || key_code == KEY_RIGHT_ARROW)
	{
		/* rotate direction */
		sign = (key_code == KEY_LEFT_ARROW) ? -1 : 1;
		rotate(&info->dir, sign * ROT_SPEED);
		rotate(&info->plane, sign * ROT_SPEED);
	}
	else if (key_code == KEY_A || key_code == KEY_D)
	{
		/*	move to left or right
			(add vector that is vertical to current direction)
		 */
		sign = (key_code == KEY_D) ? 1 : -1;
		init_vector(&rotated, info->dir.x, info->dir.y);
		rotate(&rotated, sign * M_PI_2);
		add(&info->pos, &rotated);
	}
	else if (key_code == KEY_W || key_code == KEY_S)
	{
		/* move forward or backward */
		sign = (key_code == KEY_S) ? -1 : 1;
		info->pos.x += sign * info->dir.x;
		info->pos.y += sign * info->dir.y;
	}
	else if (key_code == KEY_ESC)
		exit_hook(info);
	return (0);
}

/*
	description: 
		load texture
		hook
		run main loop
*/
void	start_game(t_info *info, int hook)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->map->res.x,
			info->map->res.y, WINDOW_TITLE);
	info->img.img = mlx_new_image(info->mlx, info->map->res.x,
			info->map->res.y);
	info->img.data = (int*)mlx_get_data_addr(info->img.img,
			&info->img.bits_per_pixel, &info->img.size_line, &info->img.endian);
	load_texture(info, &info->textures[EAST_IDX], info->map->east_texture);
	load_texture(info, &info->textures[WEST_IDX], info->map->west_texture);
	load_texture(info, &info->textures[SOUTH_IDX], info->map->south_texture);
	load_texture(info, &info->textures[NORTH_IDX], info->map->north_texture);
	load_texture(info, &info->textures[SPRITE_IDX], info->map->sprite_texture);
	init_vector(&info->pos, info->map->player.x, info->map->player.y);
	if (hook)
	{
		mlx_loop_hook(info->mlx, &main_loop, info);
		mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
		mlx_hook(info->win, 17, 0, &exit_hook, info);
		mlx_loop(info->mlx);
	}
}

int		main(int argc, char **argv)
{
	t_info	info;
	t_map	map;

	if (argc == 2)
	{
		if (load_map(&info, &map, argv[1]) == FALSE)
			error();
		info.map = &map;
		start_game(&info, TRUE);
	}
	else if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
		{
			if (load_map(&info, &map, argv[1]) == FALSE)
				error();
			info.map = &map;
			start_game(&info, FALSE);
			if (save(&info) == FALSE)
				error();
		}
	}
	return (0);
}
