/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:28:20 by mki               #+#    #+#             */
/*   Updated: 2021/01/17 11:40:38 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(void)
{	
	t_data	data;
	
	ft_init_data(&data);
	mlx_hook(data.mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &ft_key_press, &data);
	mlx_hook(data.mlx.win_ptr, X_EVENT_KEY_RELEASE, 0, &ft_key_release, &data);
	mlx_hook(data.mlx.win_ptr, X_EVENT_EXIT, 0, &ft_exit_button, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, &ft_cub3d, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
