/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:29:06 by mki               #+#    #+#             */
/*   Updated: 2021/01/20 23:18:50 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_cub3d(t_data *data)
{
	ft_move(data);
	ft_rotate(data);
	ft_screen(data);
//	ft_screen_2(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
	data->screen.img_ptr, 0, 0);
	return (0);
}
