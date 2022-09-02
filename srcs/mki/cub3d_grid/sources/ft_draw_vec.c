/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:45:41 by mki               #+#    #+#             */
/*   Updated: 2021/01/19 17:18:57 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_dir_vec(t_data *data)
{
	data->pos_dir = ft_vec_add(data->pos, ft_vec_mul(data->dir, SIZE));
	ft_line(data, data->pos, data->pos_dir, DIR_COLOR);
}

void	ft_draw_plane_vec(t_data *data)
{
	t_vec	plane_end;
	t_vec	plane_start;
	
	plane_end = ft_vec_sub(data->pos_dir, ft_vec_mul(data->plane, SIZE));
	ft_line(data, data->pos_dir, plane_end, PLANE_COLOR);
	plane_start = ft_vec_add(data->pos_dir, ft_vec_mul(data->plane, SIZE));
	ft_line(data, data->pos_dir, plane_start, PLANE_COLOR);
}

void	ft_draw_ray(t_data *data)
{
	t_vec	ray;
	double	x;
	double	w;

	x = -1;
	w = ROWS;
	while (++x < w)
	{
		data->dda.camera_x = 2 * x / w - 1;
		ray = ft_vec_add(data->dir, ft_vec_mul(data->plane, data->dda.camera_x));
		ray = ft_vec_mul(ray, 200);
		ray = ft_vec_add(data->pos, ray);
		ft_line(data, data->pos, ray, GREEN);
		data->dda.map.x = (int)data->pos.x;
		data->dda.map.y = (int)data->pos.y;
		printf("%d %d %f %f\n", data->dda.map.x, data->dda.map.y, data->pos.x, data->pos.y);
	}
}