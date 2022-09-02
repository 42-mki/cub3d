/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:48:18 by mki               #+#    #+#             */
/*   Updated: 2021/01/20 23:17:53 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_screen_clear(t_data *data)
{
	int		i;

	i = -1;
	while (++i < WIDTH * HEIGHT)
		data->screen.img_data[i] = 0;
}

void	ft_pixel(t_data *data, t_vec pixel, int color)
{
	int		x;
	int		y;

	x = pixel.x;
	y = pixel.y;
	data->screen.img_data[y * WIDTH + x] = color;
}

void	ft_screen(t_data *data)
{
	ft_screen_clear(data);
	ft_draw_lines(data);
	ft_draw_rectangles(data);
	ft_draw_player(data);
	ft_draw_dir_vec(data);
	ft_draw_plane_vec(data);
//	ft_draw_ray(data);
}
