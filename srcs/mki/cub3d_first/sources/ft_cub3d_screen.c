/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:48:18 by mki               #+#    #+#             */
/*   Updated: 2021/01/06 21:26:00 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clear_screen(t_data *data)
{
	int		i;

	i = -1;
	while (++i < WIDTH * HEIGHT)
		data->screen.img_data[i] = 0;
}

void	ft_screen(t_data *data)
{
	ft_clear_screen(data);
	ft_draw_lines(data);
	ft_draw_rectangles(data);
	ft_draw_player(data);
	ft_draw_dir_vec(data);
}
