/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:55:39 by mki               #+#    #+#             */
/*   Updated: 2021/01/15 19:23:09 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_wall_check(t_data *data)
{
	int		pos;
	int		limit;

	limit = DIR_LEN + 2;
	pos = (int)data->pos.y * WIDTH + (int)data->pos.x;
	if (data->screen.img_data[pos - limit] == W_COLOR)
		data->wall_flag[LEFT] = 1;
	else
		data->wall_flag[LEFT] = 0;
	if (data->screen.img_data[pos + limit] == W_COLOR)
		data->wall_flag[RIGHT] = 1;
	else
		data->wall_flag[RIGHT] = 0;
	if (data->screen.img_data[pos - limit * WIDTH] == W_COLOR)
		data->wall_flag[UP] = 1;
	else
		data->wall_flag[UP] = 0;
	if (data->screen.img_data[pos + limit * WIDTH] == W_COLOR)
		data->wall_flag[DOWN] = 1;
	else
		data->wall_flag[DOWN] = 0;
}

void	ft_move(t_data *data)
{
	if (data->key_flag[53])
		exit(0);
	ft_wall_check(data);
	if (data->key_flag[0] && !data->wall_flag[LEFT])
		data->pos.x -= MOVE_SPEED;
	if (data->key_flag[1] && !data->wall_flag[DOWN])
		data->pos.y += MOVE_SPEED;
	if (data->key_flag[2] && !data->wall_flag[RIGHT])
		data->pos.x += MOVE_SPEED;
	if (data->key_flag[13] && !data->wall_flag[UP])
		data->pos.y -= MOVE_SPEED;
}
