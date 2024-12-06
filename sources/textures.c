/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:20:55 by mki               #+#    #+#             */
/*   Updated: 2021/03/10 18:21:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		load_image(t_data *d, int *texture, char *path)
{
	int		x;
	int		y;
	t_image	img;

	img.img_ptr = mlx_xpm_file_to_image(d->mlx.mlx_ptr, path, &img.width,
	&img.height);
	if (!img.img_ptr)
		return (1);
	img.img_data = (int *)mlx_get_data_addr(img.img_ptr,
	&img.bits_per_pixel, &img.size_line, &img.endian);
	y = -1;
	while (++y < img.height)
	{
		x = -1;
		while (++x < img.width)
			texture[img.width * y + x] = img.img_data[img.width * y + x];
	}
	mlx_destroy_image(d->mlx.mlx_ptr, img.img_ptr);
	return (0);
}

int		load_texture(t_data *d)
{
	if (load_image(d, d->texture[0], d->tex.path[0]))
		return (1);
	if (load_image(d, d->texture[1], d->tex.path[1]))
		return (1);
	if (load_image(d, d->texture[2], d->tex.path[2]))
		return (1);
	if (load_image(d, d->texture[3], d->tex.path[3]))
		return (1);
	if (load_image(d, d->texture[4], d->tex.path[4]))
		return (1);
	return (0);
}

void	calc_textures(t_data *d, t_tex *tex)
{
	if (d->dda.side == 0)
		tex->wall_x = d->dda.pos.y + d->dda.perp_wall_dist * d->dda.ray.y;
	else
		tex->wall_x = d->dda.pos.x + d->dda.perp_wall_dist * d->dda.ray.x;
	tex->wall_x -= floor(tex->wall_x);
	tex->x = (int)(tex->wall_x * (double)TEX_WIDTH);
	if (d->dda.side == 0 && d->dda.ray.x > 0)
		tex->x = TEX_WIDTH - tex->x - 1;
	if (d->dda.side == 1 && d->dda.ray.y < 0)
		tex->x = TEX_WIDTH - tex->x - 1;
	tex->step = 1.0 * TEX_HEIGHT / d->dda.line_height;
	tex->pos = (d->dda.draw_start - d->cub.height
	/ 2 + d->dda.line_height / 2) * tex->step;
}

void	put_textures(t_data *d, t_tex *tex, int x)
{
	int		y;

	y = d->dda.draw_start - 1;
	while (++y < d->dda.draw_end)
	{
		tex->y = (int)tex->pos & (TEX_HEIGHT - 1);
		tex->pos += tex->step;
		if (d->dda.side == 0 && d->dda.ray.x < 0)
			tex->color = d->texture[3][TEX_HEIGHT * tex->y + tex->x];
		else if (d->dda.side == 0 && d->dda.ray.x > 0)
			tex->color = d->texture[2][TEX_HEIGHT * tex->y + tex->x];
		else if (d->dda.side == 1 && d->dda.ray.y > 0)
			tex->color = d->texture[0][TEX_HEIGHT * tex->y + tex->x];
		else if (d->dda.side == 1 && d->dda.ray.y < 0)
			tex->color = d->texture[1][TEX_HEIGHT * tex->y + tex->x];
		pixel_put(d, x, y, tex->color);
	}
}
