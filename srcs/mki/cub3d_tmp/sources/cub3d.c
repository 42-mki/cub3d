/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:28:08 by mki               #+#    #+#             */
/*   Updated: 2021/03/15 20:11:47 by mki              ###   ########.fr       */
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

int		cub3d(t_data *d)
{
	screen(d);
	key(d);
	if (load_texture(d))
		return (1);
	count_sprites(d, &d->spr);
	sprites_malloc(&d->spr);
	sprites_locate(d, &d->spr);
	if (d->bmp.save_flag == 1)
	{
		floor_ceiling(d);
		wall(d);
		sprites(d, &d->spr);
		bmp(d, d->screen.img_data, &d->bmp);
		return (0);
	}
	mlx_loop_hook(d->mlx.mlx_ptr, &raycasting, d);
	mlx_loop(d->mlx.mlx_ptr);
	return (0);
}
