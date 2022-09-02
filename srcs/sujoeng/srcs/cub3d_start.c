/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:46:45 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:46:47 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	mlx_init_img(void *parameter)
{
	t_map *map;

	map = (t_map *)parameter;
	map->win.mlx_img = mlx_new_image(map->win.mlx_ptr, map->res_x, map->res_y);
	if (!(map->win.str = (unsigned int *)mlx_get_data_addr(map->win.mlx_img, \
		&map->win.b_p, &map->win.s_l, &map->win.endian)))
		error_exit(map, 2);
	img_init(map);
	mlx_put_image_to_window(map->win.mlx_ptr, \
	map->win.mlx_win, map->win.mlx_img, 0, 0);
	mlx_destroy_image(map->win.mlx_ptr, map->win.mlx_img);
	return (0);
}

static void	game_loop(t_map *map)
{
	mlx_hook(map->win.mlx_win, 2, 0, key_press, map);
	mlx_hook(map->win.mlx_win, 3, 1, key_release, map);
	mlx_hook(map->win.mlx_win, 17, 2, key_esc, map);
	mlx_loop_hook(map->win.mlx_ptr, mlx_init_img, map);
	mlx_loop(map->win.mlx_ptr);
}

void		main_cub3d(t_map *map, int screen)
{
	int i;

	i = 0;
	pos_init(map);
	if (!(tex_init(map)))
		error_exit(map, 1);
	lst_malloc((void **)&map->sprite, map->sprite_nb \
	* sizeof(t_sprite *), map);
	while (i < map->sprite_nb)
	{
		lst_malloc((void **)&map->sprite[i], sizeof(t_sprite), map);
		i++;
	}
	if (!screen)
		game_loop(map);
	else
		img_init(map);
}
