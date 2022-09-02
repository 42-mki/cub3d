/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:16:11 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 16:01:07 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda_init_1(t_dda *dda, int x, int width)
{
	dda->camera_x = 2 * x / (double)width - 1;
	dda->ray.x = dda->dir.x + dda->plane.x * dda->camera_x;
	dda->ray.y = dda->dir.y + dda->plane.y * dda->camera_x;
	dda->map.x = (int)dda->pos.x;
	dda->map.y = (int)dda->pos.y;
	dda->delta_dist.x = fabs(1 / dda->ray.x);
	dda->delta_dist.y = fabs(1 / dda->ray.y);
}

void	dda_init_2(t_dda *dda)
{
	if (dda->ray.x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = (dda->pos.x - dda->map.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->map.x + 1.0 - dda->pos.x) * dda->delta_dist.x;
	}
	if (dda->ray.y < 0)
	{
		dda->step.y = -1;
		dda->side_dist.y = (dda->pos.y - dda->map.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->map.y + 1.0 - dda->pos.y) * dda->delta_dist.y;
	}
}

void	dda(t_data *d)
{
	d->dda.hit = 0;
	while (d->dda.hit == 0)
	{
		if (d->dda.side_dist.x <= d->dda.side_dist.y)
		{
			d->dda.side_dist.x += d->dda.delta_dist.x;
			d->dda.map.x += d->dda.step.x;
			d->dda.side = 0;
		}
		else
		{
			d->dda.side_dist.y += d->dda.delta_dist.y;
			d->dda.map.y += d->dda.step.y;
			d->dda.side = 1;
		}
		if (d->cub.world_map[d->dda.map.x][d->dda.map.y] == 1)
			d->dda.hit = 1;
	}
}

void	draw(t_data *d, int x)
{
	if (d->dda.side == 0)
		d->dda.perp_wall_dist = (d->dda.map.x - d->dda.pos.x
		+ (1 - d->dda.step.x) / 2) / d->dda.ray.x;
	else
		d->dda.perp_wall_dist = (d->dda.map.y - d->dda.pos.y
		+ (1 - d->dda.step.y) / 2) / d->dda.ray.y;
	d->dda.buffer[x] = d->dda.perp_wall_dist;
	d->dda.line_height = (int)(d->cub.height / d->dda.perp_wall_dist);
	d->dda.draw_start = d->cub.height / 2 - d->dda.line_height / 2;
	if (d->dda.draw_start < 0)
		d->dda.draw_start = 0;
	d->dda.draw_end = d->cub.height / 2 + d->dda.line_height / 2;
	if (d->dda.draw_end >= d->cub.height)
		d->dda.draw_end = d->cub.height - 1;
}

void	wall(t_data *d)
{
	int		x;

	x = -1;
	while (++x < d->cub.width)
	{
		dda_init_1(&d->dda, x, d->cub.width);
		dda_init_2(&d->dda);
		dda(d);
		draw(d, x);
		calc_textures(d, &d->tex);
		put_textures(d, &d->tex, x);
	}
}
