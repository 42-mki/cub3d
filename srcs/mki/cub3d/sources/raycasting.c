/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:54:47 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 15:32:48 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_1(t_data *data, t_cub *cub, t_vec_d *p, t_vec_d *d)
{
	if (data->key_flag[KEY_W])
	{
		if (cub->world_map[(int)(p->x + d->x * MOVE_SPEED)][(int)p->y] == 0)
			p->x += d->x * MOVE_SPEED / 5;
		if (cub->world_map[(int)(p->x)][(int)(p->y + d->y * MOVE_SPEED)] == 0)
			p->y += d->y * MOVE_SPEED / 5;
	}
	if (data->key_flag[KEY_S])
	{
		if (cub->world_map[(int)(p->x - d->x * MOVE_SPEED)][(int)p->y] == 0)
			p->x -= d->x * MOVE_SPEED / 5;
		if (cub->world_map[(int)(p->x)][(int)(p->y - d->y * MOVE_SPEED)] == 0)
			p->y -= d->y * MOVE_SPEED / 5;
	}
}

void	move_2(t_data *data, t_cub *cub, t_vec_d *p, t_vec_d *d)
{
	if (data->key_flag[KEY_D])
	{
		if (cub->world_map[(int)(p->x + d->x * MOVE_SPEED)][(int)p->y] == 0)
			p->x += d->x * MOVE_SPEED / 5;
		if (cub->world_map[(int)(p->x)][(int)(p->y + d->y * MOVE_SPEED)] == 0)
			p->y += d->y * MOVE_SPEED / 5;
	}
	if (data->key_flag[KEY_A])
	{
		if (cub->world_map[(int)(p->x - d->x * MOVE_SPEED)][(int)p->y] == 0)
			p->x -= d->x * MOVE_SPEED / 5;
		if (cub->world_map[(int)(p->x)][(int)(p->y - d->y * MOVE_SPEED)] == 0)
			p->y -= d->y * MOVE_SPEED / 5;
	}
}

void	move_3(t_data *d)
{
	if (d->key_flag[ARROW_L])
	{
		d->dda.dir = ft_rotate_vec(d->dda.dir, d->tri, LEFT);
		d->dda.plane = ft_rotate_vec(d->dda.plane, d->tri, LEFT);
	}
	if (d->key_flag[ARROW_R])
	{
		d->dda.dir = ft_rotate_vec(d->dda.dir, d->tri, RIGHT);
		d->dda.plane = ft_rotate_vec(d->dda.plane, d->tri, RIGHT);
	}
	if (d->key_flag[KEY_ESC])
		exit(0);
}

void	floor_ceiling(t_data *d)
{
	int		i;

	i = -1;
	while (++i < d->cub.width * d->cub.height / 2)
		d->screen.img_data[i] = d->cub.ceiling;
	while (++i < d->cub.width * d->cub.height)
		d->screen.img_data[i] = d->cub.floor;
}

int		raycasting(t_data *d)
{
	floor_ceiling(d);
	wall(d);
	sprites(d, &d->spr);
	mlx_put_image_to_window(d->mlx.mlx_ptr, d->mlx.win_ptr,
	d->screen.img_ptr, 0, 0);
	move_1(d, &d->cub, &d->dda.pos, &d->dda.dir);
	move_2(d, &d->cub, &d->dda.pos, &d->dda.plane);
	move_3(d);
	return (0);
}
