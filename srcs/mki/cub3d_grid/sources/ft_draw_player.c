/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:29:16 by mki               #+#    #+#             */
/*   Updated: 2021/01/19 09:05:19 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

void	ft_draw_player(t_data *data)
{
	t_vec	idx;

	idx.y = -P_SIZE / 2;
	while (idx.y <= P_SIZE / 2)
	{
		idx.x = -P_SIZE / 2;
		while (idx.x <= P_SIZE / 2)
		{
			ft_pixel(data, ft_vec_add(data->pos, idx), PLAYER_COLOR);
			idx.x++;
		}
		idx.y++;
	}
}
