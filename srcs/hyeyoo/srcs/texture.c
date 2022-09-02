/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:04:48 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 17:57:32 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "info.h"
#include <mlx.h>
#include <math.h>
#include "error.h"
#include <stdlib.h>

void	load_texture(t_info *info, t_image *img, char *path)
{
	int		img_width;
	int		img_height;
	int		y;
	int		x;
	int		tmp;

	if ((img->img = mlx_xpm_file_to_image(info->mlx, path, \
					&img_width, &img_height)) == NULL)
		error();
	img->data = (int*)mlx_get_data_addr(img->img, &img->bits_per_pixel,\
				&img->size_line, &img->endian);
	y = 0;
	while (y < TEXTURE_HEIGHT)
	{
		x = 0;
		while (x < TEXTURE_WIDTH / 2)
		{
			tmp = img->data[y * TEXTURE_WIDTH + TEXTURE_WIDTH - x - 1];
			img->data[y * TEXTURE_WIDTH + TEXTURE_WIDTH - x - 1] =\
				img->data[y * TEXTURE_WIDTH + x];
			img->data[y * TEXTURE_WIDTH + x] = tmp;
			x++;
		}
		y++;
	}
}

int		get_direction(t_vector ray_dir, int side)
{
	if (ray_dir.x >= 0 && ray_dir.y >= 0)
	{
		return ((side == 0) ? WEST_IDX : NORTH_IDX);
	}
	else if (ray_dir.x <= 0 && ray_dir.y >= 0)
	{
		return ((side == 0) ? EAST_IDX : NORTH_IDX);
	}
	else if (ray_dir.x <= 0 && ray_dir.y <= 0)
	{
		return ((side == 0) ? EAST_IDX : SOUTH_IDX);
	}
	else
	{
		return ((side == 0) ? WEST_IDX : SOUTH_IDX);
	}
}
