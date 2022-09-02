/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:08:43 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 17:04:08 by hyeyoo           ###   ########.fr       */
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

void	set_dist_direction(t_info *info, t_var *v)
{
	v->map.x = (int)info->pos.x;
	v->map.y = (int)info->pos.y;
	if (v->ray_dir.y == 0)
		v->delta_dist.x = 0;
	else if (v->ray_dir.x == 0)
		v->delta_dist.x = 1;
	else
		v->delta_dist.x = fabs(1 / v->ray_dir.x);
	if (v->ray_dir.x == 0)
		v->delta_dist.y = 0;
	else if (v->ray_dir.y == 0)
		v->delta_dist.y = 1;
	else
		v->delta_dist.y = fabs(1 / v->ray_dir.y);
	v->step.x = (v->ray_dir.x < 0) ? -1 : 1;
	v->side_dist.x = (v->ray_dir.x < 0) ? (info->pos.x - v->map.x) * \
	v->delta_dist.x : (v->map.x + 1.0 - info->pos.x) * v->delta_dist.x;
	v->step.y = (v->ray_dir.y < 0) ? -1 : 1;
	v->side_dist.y = (v->ray_dir.y < 0) ? (info->pos.y - v->map.y) * \
	v->delta_dist.y : (v->map.y + 1.0 - info->pos.y) * v->delta_dist.y;
}

void	draw_sprites(t_info *info, t_var *v)
{
	v->stripe = v->draw_start_x;
	while (v->stripe < v->draw_end_x)
	{
		v->tex_x = (int)(256 * (v->stripe - (-v->sprite_width / 2 + \
			v->sprite_screen_x)) * TEXTURE_WIDTH / v->sprite_width) / 256;
		if (v->transform.y > 0 && v->stripe > 0 && v->stripe < \
			info->map->res.x && v->transform.y < v->z_buffer[v->stripe])
		{
			v->y = v->draw_start_y;
			while (v->y < v->draw_end_y)
			{
				v->d = v->y * 256 - info->map->res.y * 128 + \
						v->sprite_height * 128;
				v->tex_y = ((v->d * TEXTURE_HEIGHT) / v->sprite_height) / 256;
				v->color = info->textures[SPRITE_IDX].data[v->tex_y * \
						TEXTURE_WIDTH + v->tex_x];
				if ((v->color & 0x00FFFFFF) != 0)
					info->img.data[v->y * info->map->res.x + \
						v->stripe] = v->color;
				v->y++;
			}
		}
		v->stripe++;
	}
}

void	draw_sprites_prep(t_info *info, t_var *v, int i)
{
	v->sprites[i].x -= info->pos.x;
	v->sprites[i].y -= info->pos.y;
	v->inv_det = 1.0 / (info->plane.x * info->dir.y - \
			info->dir.x * info->plane.y);
	v->transform.x = v->inv_det * (info->dir.y * v->sprites[i].x - \
			info->dir.x * v->sprites[i].y);
	v->transform.y = v->inv_det * (-info->plane.y * v->sprites[i].x + \
			info->plane.x * v->sprites[i].y);
	v->sprite_screen_x = (int)((info->map->res.x / 2) * \
			(1 + v->transform.x / v->transform.y));
	v->sprite_height = abs((int)(info->map->res.y / v->transform.y));
	v->draw_start_y = -v->sprite_height / 2 + info->map->res.y / 2;
	if (v->draw_start_y < 0)
		v->draw_start_y = 0;
	v->draw_end_y = v->sprite_height / 2 + info->map->res.y / 2;
	if (v->draw_end_y >= info->map->res.y)
		v->draw_end_y = info->map->res.y - 1;
	v->sprite_width = abs((int)(info->map->res.y / v->transform.y));
	v->draw_start_x = -v->sprite_width / 2 + v->sprite_screen_x;
	if (v->draw_start_x < 0)
		v->draw_start_x = 0;
	v->draw_end_x = v->sprite_width / 2 + v->sprite_screen_x;
	if (v->draw_end_x >= info->map->res.x)
		v->draw_end_x = info->map->res.x - 1;
}

void	render_sprites(t_info *info, t_var *v)
{
	int			n_sprites;
	int			i;

	n_sprites = number_of_sprites(info->map);
	v->sprites = (t_sprite*)malloc(sizeof(t_sprite) * n_sprites);
	load_sprites(info, v->sprites);
	sort_sprites(v->sprites, n_sprites);
	i = 0;
	while (i < n_sprites)
	{
		draw_sprites_prep(info, v, i);
		draw_sprites(info, v);
		i++;
	}
	free(v->z_buffer);
	free(v->sprites);
}
