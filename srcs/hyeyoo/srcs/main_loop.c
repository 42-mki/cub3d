/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:08:43 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:50:28 by hyeyoo           ###   ########.fr       */
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

void	calc_perp_wall_dist(t_info *info, t_var *v)
{
	v->hit = FALSE;
	while (v->hit == FALSE)
	{
		if (v->side_dist.x < v->side_dist.y)
		{
			v->side_dist.x += v->delta_dist.x;
			v->map.x += v->step.x;
			v->side = 0;
		}
		else
		{
			v->side_dist.y += v->delta_dist.y;
			v->map.y += v->step.y;
			v->side = 1;
		}
		if (info->map->map[v->map.y][v->map.x] == WALL)
			v->hit = TRUE;
	}
	if (v->side == 0)
		v->perp_wall_dist = (v->map.x - info->pos.x + \
			(1 - v->step.x) / 2) / v->ray_dir.x;
	else
		v->perp_wall_dist = (v->map.y - info->pos.y + \
			(1 - v->step.y) / 2) / v->ray_dir.y;
}

void	draw_prep(t_info *info, t_var *v)
{
	v->line_height = (int)(info->map->res.y / v->perp_wall_dist);
	v->draw_start = -v->line_height / 2 + info->map->res.y / 2;
	if (v->draw_start < 0)
		v->draw_start = 0;
	v->draw_end = v->line_height / 2 + info->map->res.y / 2;
	if (v->draw_end >= info->map->res.y)
		v->draw_end = info->map->res.y - 1;
	v->tex_num = get_direction(v->ray_dir, v->side);
	if (v->side == 0)
		v->wall_x = info->pos.y + v->ray_dir.y * v->perp_wall_dist;
	else
		v->wall_x = info->pos.x + v->ray_dir.x * v->perp_wall_dist;
	v->wall_x -= floor(v->wall_x);
	v->tex_x = (int)(v->wall_x * (double)TEXTURE_WIDTH);
	if ((v->side == 0 && v->ray_dir.x > 0) ||
			(v->side == 1 && v->ray_dir.y < 0))
		v->tex_x = TEXTURE_WIDTH - v->tex_x - 1;
	v->dy = 1.0 * TEXTURE_HEIGHT / v->line_height;
	v->tex_pos = (v->draw_start - info->map->res.y / 2 + \
			v->line_height / 2) * v->dy;
}

void	draw(t_info *info, t_var *v)
{
	v->color = 0;
	v->y = 0;
	while (v->y < info->map->res.y)
	{
		if (v->y < v->draw_start)
		{
			v->color = info->map->ceil_color;
		}
		else if (v->y <= v->draw_end)
		{
			v->tex_y = (int)v->tex_pos & (TEXTURE_HEIGHT - 1);
			v->tex_pos += v->dy;
			v->color = info->textures[v->tex_num].data[v->tex_y * \
					TEXTURE_HEIGHT + v->tex_x];
			if (v->side == 1)
				v->color = (v->color >> 1) & 8355711;
		}
		else if (v->y <= info->map->res.y)
		{
			v->color = info->map->floor_color;
		}
		info->img.data[v->y * info->map->res.x + v->x] = v->color;
		v->y++;
	}
}

void	render_walls(t_info *info, t_var *v)
{
	v->z_buffer = (double*)malloc(sizeof(double) * info->map->res.x);
	v->x = 0;
	while (v->x < info->map->res.x)
	{
		v->camera_x = 2 * v->x / (double)info->map->res.x - 1;
		init_vector(&v->ray_dir, info->dir.x + info->plane.x * v->camera_x, \
				info->dir.y + info->plane.y * v->camera_x);
		set_dist_direction(info, v);
		calc_perp_wall_dist(info, v);
		draw_prep(info, v);
		draw(info, v);
		v->z_buffer[v->x] = v->perp_wall_dist;
		v->x++;
	}
}

int		main_loop(t_info *info)
{
	t_var	v;

	render_walls(info, &v);
	render_sprites(info, &v);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	clear(&info->img);
	return (0);
}
