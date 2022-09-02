/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:29:20 by mki               #+#    #+#             */
/*   Updated: 2021/01/06 19:25:47 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_lines(t_data *data)
{
	int		cnt_rows;
	int		cnt;

	cnt = 0;
	while (cnt < WIDTH * HEIGHT)
	{
		data->screen.img_data[cnt] = L_COLOR;
		cnt += SIZE;
	}
	cnt_rows = -1; 
	while (++cnt_rows < ROWS)
	{
		cnt = -1;
		while (++cnt < WIDTH)
			data->screen.img_data[cnt + cnt_rows * WIDTH * SIZE] = L_COLOR;
	}
}

void	ft_draw_rectangle(t_data *data, int row, int col)
{
	int		i;
	int		j;

	row *= SIZE;
	col *= SIZE;
	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			data->screen.img_data[(row + i) * WIDTH + col + j] = W_COLOR;
	}
}

void	ft_draw_rectangles(t_data *data)
{
	int		row;
	int		col;

	row = -1;
	while (++row < ROWS)
	{
		col = -1;
		while (++col < COLS)
			if (data->map_source[row][col] == 1)
				ft_draw_rectangle(data, row, col);
	}
}
