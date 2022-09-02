/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:28:08 by mki               #+#    #+#             */
/*   Updated: 2021/02/04 22:53:04 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	screen(t_data *d)
{
	d->mlx.mlx_ptr = mlx_init();
	d->mlx.win_ptr = mlx_new_window(d->mlx.mlx_ptr,
	d->cub.width, d->cub.height, "cub3D");
	d->screen.img_ptr = mlx_new_image(d->mlx.mlx_ptr,
	d->cub.width, d->cub.height);
	d->screen.img_data = (int *)mlx_get_data_addr(d->screen.img_ptr,
	&d->screen.bits_per_pixel, &d->screen.size_line, &d->screen.endian);
}

void	init_vec(t_data *d)
{
	d->dda.pos.x = 12.5;
	d->dda.pos.y = 12.5;
	d->dda.dir.x = -1.0;
	d->dda.dir.y = 0.0;
	d->dda.plane.x = 0.0;
	d->dda.plane.y = 1.0;
	d->tri.sin_p = sin(M_PI * ROTATE_SPEED / 180);
	d->tri.sin_m = sin(-M_PI * ROTATE_SPEED / 180);
	d->tri.cos_p = cos(M_PI * ROTATE_SPEED / 180);
	d->tri.cos_m = cos(-M_PI * ROTATE_SPEED / 180);
}

int		cub3d(t_data *d)
{
	screen(d);
	key(d);
	init_vec(d);
	load_texture(d);
	mlx_loop_hook(d->mlx.mlx_ptr, &raycasting, d);
	mlx_loop(d->mlx.mlx_ptr);
	return (0);
}
