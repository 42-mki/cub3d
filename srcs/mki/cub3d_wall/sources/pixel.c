/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:05:59 by mki               #+#    #+#             */
/*   Updated: 2021/02/02 16:07:33 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(t_data *d, int x, int y, int color)
{
	d->screen.img_data[d->cub.width * y + x] = color;
}

void	ver_line(t_data *d, int x, int color)
{
	int		y;

	y = d->dda.draw_start;
	while (y <= d->dda.draw_end)
	{
		pixel_put(d, x, y, color);
		y++;
	}
}
