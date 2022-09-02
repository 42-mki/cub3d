/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:29:16 by mki               #+#    #+#             */
/*   Updated: 2021/01/06 19:20:00 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

void	ft_draw_player(t_data *data)
{
	int		i;
	int		j;

	i = -P_SIZE / 2;
	while (i <= P_SIZE / 2)
	{
		j = -P_SIZE / 2;
		while (j <= P_SIZE / 2)
			data->screen.img_data[(WIDTH * ((int)data->pos.y + i)) + (int)data->pos.x + j++] = P_COLOR;
		i++;
	}
}
