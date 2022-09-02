/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:46:58 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:47:00 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		update_sprite(t_map *map)
{
	int i;

	i = 0;
	while (i <= map->sprite_nb &&
		(map->sprite[i]->map_x || map->sprite[i]->map_y))
	{
		map->sprite[i]->distance = (map->player.pos_x - \
		(map->sprite[i]->map_x + 0.5)) * (map->player.pos_x \
		- (map->sprite[i]->map_x + 0.5)) + (map->player.pos_y \
		- (map->sprite[i]->map_y + 0.5)) * (map->player.pos_y - \
		(map->sprite[i]->map_y + 0.5));
		i++;
	}
}

static int	find_wall(t_map *map)
{
	if (map->player.side == 0 && map->player.ray_x >= 0)
		return (EAST);
	else if (map->player.side == 0 && map->player.ray_x < 0)
		return (WEST);
	else if (map->player.side == 1 && map->player.ray_y < 0)
		return (NORTH);
	else
		return (SOUTH);
}

void		draw_img(t_map *map)
{
	int		wall_text;
	int		i;
	int		textx;
	int		texty;
	int		c;

	wall_text = find_wall(map);
	texty = 0;
	textx = map->player.wallx * map->texture[wall_text].width;
	i = -1;
	if (map->player.rdraws < 0)
		i = abs(map->player.rdraws);
	while (map->player.drawstart <= map->player.drawend)
	{
		if (++i * map->texture[wall_text].height / (int)map->player.lheight \
		>= map->texture[wall_text].height)
			texty = map->texture[wall_text].height - 1;
		else
			texty = i * map->texture[wall_text].height \
			/ (int)map->player.lheight;
		map->win.str[(map->res_x * map->player.drawstart) \
			+ map->player.x] = map->texture[wall_text].img[(texty \
			* (map->texture[wall_text].s_l / 4)) + textx];
		map->player.drawstart++;
	}
}
