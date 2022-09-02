/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:29:41 by mki               #+#    #+#             */
/*   Updated: 2021/01/19 00:22:52 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_vertical(t_data *data, t_vec s, int color)
{
	t_vec	idx;
	int		cnt;

	if (data->line.sign.y < 0)
		data->line.delta.y *= -1;
	idx.x = 0;
	idx.y = 0;
	cnt = -1;
	while (++cnt < data->line.delta.y)
	{
		ft_pixel(data, ft_vec_add(s, idx), color);
		idx.y += data->line.sign.y;
	}
}

void	ft_horizontal(t_data *data, t_vec s, int color)
{
	t_vec	idx;
	int		cnt;

	if (data->line.sign.x < 0)
		data->line.delta.x *= -1;
	idx.x = 0;
	idx.y = 0;
	cnt = -1;
	while (++cnt < data->line.delta.x)
	{
		ft_pixel(data, ft_vec_add(s, idx), color);
		idx.x += data->line.sign.x;
	}
}

void	ft_cross_0(t_data *data, t_vec s, int color)
{
	int		cnt;
	t_vec	idx;

	cnt = -1;
	idx.x = 0;
	idx.y = 0;
	if (data->line.sign.x < 0)
		data->line.delta.x *= -1;
	while (++cnt < (int)data->line.delta.x)
	{
		ft_pixel(data, ft_vec_add(s, idx), color);
		idx.x += data->line.sign.x;
		if (data->line.sign.x < 0)
			idx.y -= data->line.m;
		else
			idx.y += data->line.m;
	}
}
void	ft_cross_1(t_data *data, t_vec s, int color)
{
	int		cnt;
	t_vec	idx;

	cnt = -1;
	idx.x = 0;
	idx.y = 0;
	if (data->line.sign.y < 0)
		data->line.delta.y *= -1;
	while (++cnt < (int)data->line.delta.y) 
	{
		ft_pixel(data, ft_vec_add(s, idx), color);
		idx.y += data->line.sign.y;
		idx.x = idx.y / data->line.m;
	}
}

void	ft_line(t_data *data, t_vec start, t_vec end, int color)
{
	data->line.delta = ft_vec_sub(end, start);
	data->line.sign.x = data->line.delta.x > 0 ? 1 : -1;
	data->line.sign.y = data->line.delta.y > 0 ? 1 : -1;
	if (!data->line.delta.x)
		ft_vertical(data, start, color);
	else if (!data->line.delta.y)
		ft_horizontal(data, start, color);
	else
	{
		data->line.m = data->line.delta.y / data->line.delta.x;
		if (-1 < data->line.m && data->line.m < 1)
			ft_cross_0(data, start, color);
		else
			ft_cross_1(data, start, color);
	}
}
