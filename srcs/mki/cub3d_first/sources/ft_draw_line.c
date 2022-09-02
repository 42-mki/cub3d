/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:29:41 by mki               #+#    #+#             */
/*   Updated: 2021/01/17 11:41:29 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_vertical(t_data *data, t_vec s)
{
	int		i;
	int		count;
	int		sign;

	sign = data->dda.delta_y > 0 ? 1 : -1;
	data->dda.delta_y = sign == 1 ? data->dda.delta_y : -data->dda.delta_y;
	i = 0;
	count = -1;
	while (++count < data->dda.delta_y)
	{
		data->screen.img_data[(int)((s.y + i) * WIDTH + s.x)] = P_COLOR;
		i += sign;
	}
}

void	ft_horizontal(t_data *data, t_vec s)
{
	int		i;
	int		count;
	int		sign;

	sign = data->dda.delta_x > 0 ? 1 : -1;
	data->dda.delta_x = sign == 1 ? data->dda.delta_x : -data->dda.delta_x;
	i = 0;
	count = -1;
	while (++count < data->dda.delta_x)
	{
		data->screen.img_data[(int)(s.y * WIDTH + s.x + i)] = P_COLOR;
		i += sign;
	}
}

void	ft_line(t_data *data)
{
	int		count;
	double	i;
	double	j;

	count = -1;
	i = 0;
	j = 0;
	if (-1 < data->dda.m && data->dda.m < 1)
	{
		while (++count < DIR_LEN)
		{
			data->screen.img_data[(int)((int)(data->pos.y + j) * WIDTH + data->pos.x + i)] = P_COLOR;
			i += data->dda.step_x;
			if (data->dda.step_x < 0)
				j -= data->dda.m;
			else
				j += data->dda.m;
		}
	}
	else
		while (++count < DIR_LEN)
		{
			data->screen.img_data[(int)((data->pos.y + j) * WIDTH + data->pos.x + i)] = P_COLOR;
			j += data->dda.step_y;
			i = j / data->dda.m;
		}
}

void	ft_dda(t_data *data, t_vec start, t_vec end)
{
	data->dda.delta_x = end.x - start.x;
	data->dda.delta_y = end.y - start.y;
	if (!(int)data->dda.delta_x)
		ft_vertical(data, start);
	else if (!(int)data->dda.delta_y)
		ft_horizontal(data, start);
	else
	{
		data->dda.m = data->dda.delta_y / data->dda.delta_x;
		data->dda.step_x = data->dda.delta_x > 0 ? 1 : -1;
		data->dda.step_y = data->dda.delta_y > 0 ? 1 : -1;
		ft_line(data);
	}
}