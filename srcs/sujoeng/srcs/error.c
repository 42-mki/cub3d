/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:47:04 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:47:06 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	error_msgs(int nb)
{
	if (nb)
		ft_putstr_fd("error: ", 2);
	else
		ft_putstr_fd("add screenshot\n", 1);
	nb == 1 ? ft_putstr_fd("invalid map\n", 2) : 0;
	nb == 2 ? ft_putstr_fd("memory allocated\n", 2) : 0;
}

int			error_exit(t_map *map, int nb)
{
	if (map->win.mlx_img)
		mlx_destroy_image(map->win.mlx_ptr, map->win.mlx_img);
	free(map->text_path.no);
	free(map->text_path.so);
	free(map->text_path.we);
	free(map->text_path.ea);
	free(map->text_path.spr);
	ft_lstclear(&(map->map_tmp), &free);
	ft_lstclear(&(map->trash), &free);
	free(map);
	error_msgs(nb);
	exit(0);
}
