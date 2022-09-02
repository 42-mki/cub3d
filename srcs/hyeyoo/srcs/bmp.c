/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:15:23 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 16:13:46 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "common.h"
#include <fcntl.h>
#include "unistd.h"
#include "libft.h"
#include "bmp.h"

void	init_bmp(t_info *info, t_bmp *bmp)
{
	bmp->bmp[0] = 'B';
	bmp->bmp[1] = 'M';
	bmp->size = 54 + 4 * info->map->res.x * info->map->res.y;
	bmp->unused = 0;
	bmp->offset = 54;
	bmp->dib = 54 - 14;
	bmp->width = info->map->res.x;
	bmp->height = -info->map->res.y;
	bmp->plane[0] = 1;
	bmp->plane[1] = 0;
	bmp->bpp[0] = 32;
	bmp->bpp[1] = 0;
	bmp->compression = 0;
	bmp->raw_bitmap_size = 4 * info->map->res.x * info->map->res.y;
	bmp->res_x = 0;
	bmp->res_y = 0;
	bmp->n_colors = 0;
	bmp->important_colors = 0;
}

int		save(t_info *info)
{
	int		fd;
	t_bmp	bmp;
	t_var	v;

	render_walls(info, &v);
	render_sprites(info, &v);
	init_bmp(info, &bmp);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
					O_TRUNC | O_APPEND, 0666)) < 0)
		return (FALSE);
	else if (write(fd, &bmp, 54) < 0)
		return (FALSE);
	else if (write(fd, info->img.data, bmp.raw_bitmap_size) < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}
