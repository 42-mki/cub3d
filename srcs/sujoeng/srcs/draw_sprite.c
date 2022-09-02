/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:46:51 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:46:53 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		loop_sprites2(t_map *map, int y, int *stripe, int i)
{
	int color;
	int d;
	int	texty;

	while (y < map->sprite[i]->drawend_y)
	{
		d = y * 256 - map->res_y * 128 + map->sprite[i]->sprite_h * 128;
		texty = ((d * map->texture[SPRITE].height) /\
		map->sprite[i]->sprite_h) / 256;
		color = map->texture[SPRITE].img\
		[(map->texture[SPRITE].s_l / 4) * texty + map->textx];
		if (color != 16777215)
			map->win.str[map->res_x * y + *stripe] = color;
		y++;
	}
}

void			loop_sprites(t_map *map, int i)
{
	int stripe;
	int y;

	stripe = map->sprite[i]->drawstart_x;
	y = map->sprite[i]->drawstart_y;
	while (stripe < map->sprite[i]->drawend_x)
	{
		map->textx = (256 * (stripe - (-map->sprite[i]->sprite_w \
			/ 2 + map->sprite[i]->spritescreenx)) * map->texture[SPRITE].width \
			/ map->sprite[i]->sprite_w) / 256;
		y = map->sprite[i]->drawstart_y;
		if (map->sprite[i]->transformy > 0 && stripe > 0 && stripe \
		< map->res_x && map->sprite[i]->transformy < map->zbuffer[stripe])
			loop_sprites2(map, y, &stripe, i);
		stripe++;
	}
}

static void		sprite_init3(t_map *map, int i)
{
	map->sprite[i]->drawstart_y = -map->sprite[i]->sprite_h / 2
	+ map->res_y / 2;
	if (map->sprite[i]->drawstart_y < 0)
		map->sprite[i]->drawstart_y = 0;
	map->sprite[i]->drawend_y = map->sprite[i]->sprite_h / 2 + map->res_y / 2;
	if (map->sprite[i]->drawend_y >= map->res_y)
		map->sprite[i]->drawend_y = map->res_y - 1;
	map->sprite[i]->sprite_w = abs((int)((double)map->res_y \
		/ map->sprite[i]->transformy));
	map->sprite[i]->drawstart_x = -map->sprite[i]->sprite_w \
		/ 2 + map->sprite[i]->spritescreenx;
	if (map->sprite[i]->drawstart_x < 0)
		map->sprite[i]->drawstart_x = 0;
	map->sprite[i]->drawend_x = map->sprite[i]->sprite_w \
		/ 2 + map->sprite[i]->spritescreenx;
	if (map->sprite[i]->drawend_x >= map->res_x)
		map->sprite[i]->drawend_x = map->res_x - 1;
}

static void		sprite_init2(t_map *map, int i)
{
	map->sprite[i]->transformx = map->sprite[i]->invdet \
	* (map->player.dir_y * map->sprite[i]->spritex - \
	map->player.dir_x * map->sprite[i]->spritey);
	map->sprite[i]->transformy = map->sprite[i]->invdet * \
	(-map->player.plane_y * map->sprite[i]->spritex + \
	map->player.plane_x * map->sprite[i]->spritey);
	map->sprite[i]->spritescreenx = (int)(((double)map->res_x / 2) * \
		(1.0 + (map->sprite[i]->transformx / map->sprite[i]->transformy)));
	map->sprite[i]->sprite_h = abs((int)((double)map->res_y \
		/ (map->sprite[i]->transformy)));
}

void			sprite_init(t_map *map)
{
	int i;

	i = 0;
	while (i < map->sprite_nb &&\
		(map->sprite[i]->map_x || map->sprite[i]->map_y))
	{
		map->sprite[i]->spritex = (map->sprite[i]->map_x + 0.5)\
		- map->player.pos_x;
		map->sprite[i]->spritey = (map->sprite[i]->map_y + 0.5)\
		- map->player.pos_y;
		map->sprite[i]->invdet = 1.0 / (map->player.plane_x * \
		map->player.dir_y - map->player.dir_x * map->player.plane_y);
		sprite_init2(map, i);
		sprite_init3(map, i);
		i++;
	}
}
