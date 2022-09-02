/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:48:13 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:48:14 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	img_init4(t_map *map)
{
	map->player.rdraws = (map->res_y / 2) - (map->player.lheight / 2);
	if (map->player.rdraws <= 0)
		map->player.drawstart = 0;
	else
		map->player.drawstart = map->player.rdraws;
	map->player.drawend = map->player.drawstart + map->player.lheight;
	if (map->player.drawend >= map->res_y)
		map->player.drawend = map->res_y - 1;
	if (map->player.side == 0)
		map->player.wallx = map->player.pos_y + map->player.perpwall_dist *\
			map->player.ray_y;
	else
		map->player.wallx = map->player.pos_x + map->player.perpwall_dist *\
			map->player.ray_x;
	map->player.wallx -= floor(map->player.wallx);
}

static void	perform_dda(t_map *map)
{
	map->player.hit = 0;
	while (map->player.hit == 0)
	{
		if (map->player.side_x < map->player.side_y)
		{
			map->player.side_x += map->player.delta_x;
			map->map_x += map->player.stepx;
			map->player.side = 0;
		}
		else
		{
			map->player.side_y += map->player.delta_y;
			map->map_y += map->player.stepy;
			map->player.side = 1;
		}
		if (map->map[map->map_y][map->map_x] == 1)
			map->player.hit = 1;
		if (map->map[map->map_y][map->map_x] == 2)
			store_sprite(map);
	}
	if (map->player.side == 0)
		map->player.perpwall_dist = ((double)map->map_x \
		- (double)map->player.pos_x + \
			((1.0 - (double)map->player.stepx) / 2.0)) / map->player.ray_x;
}

static void	img_init3(t_map *map)
{
	if (map->player.ray_y < 0)
	{
		map->player.stepy = -1;
		map->player.side_y = (map->player.pos_y - map->map_y) \
			* map->player.delta_y;
	}
	else
	{
		map->player.stepy = 1;
		map->player.side_y = (map->map_y + 1.0 - map->player.pos_y) \
			* map->player.delta_y;
	}
	perform_dda(map);
	if (map->player.side != 0)
		map->player.perpwall_dist = ((double)map->map_y - \
		(double)map->player.pos_y + ((1.0 - (double)map->player.stepy) / 2.0))\
		/ map->player.ray_y;
	if (map->player.perpwall_dist > 0)
		map->player.lheight = (double)map->res_y / map->player.perpwall_dist;
	else
		map->player.lheight = ((double)map->res_y - 1.0);
	img_init4(map);
}

static void	img_init2(t_map *map)
{
	map->map_x = (int)map->player.pos_x;
	map->map_y = (int)map->player.pos_y;
	map->player.delta_x = fabs(1 / map->player.ray_x);
	map->player.delta_y = fabs(1 / map->player.ray_y);
	if (map->player.ray_x < 0)
	{
		map->player.stepx = -1;
		map->player.side_x = (map->player.pos_x - map->map_x) \
			* map->player.delta_x;
	}
	else
	{
		map->player.stepx = 1;
		map->player.side_x = (map->map_x + 1.0 - map->player.pos_x) \
			* map->player.delta_x;
	}
	img_init3(map);
}

void		img_init(t_map *map)
{
	if (map->key)
		moves(map);
	lst_malloc((void **)&map->zbuffer, map->res_x * sizeof(double), map);
	map->player.x = 0;
	sky_floor(map);
	while (map->player.x < map->res_x)
	{
		map->player.camerax = 2.0 * (double)map->player.x / \
			(double)map->res_x - 1.0;
		map->player.ray_x = map->player.dir_x + map->player.plane_x \
			* map->player.camerax;
		map->player.ray_y = map->player.dir_y + map->player.plane_y \
			* map->player.camerax;
		img_init2(map);
		draw_img(map);
		map->zbuffer[map->player.x] = map->player.perpwall_dist;
		map->player.x++;
	}
	sprite_loop(map);
}
