/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:47:19 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:47:21 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		esc_game(t_map *map)
{
	ft_putstr_fd("cub3d exit\n", 2);
	mlx_destroy_image(map->win.mlx_ptr, map->win.mlx_img);
	free(map->text_path.no);
	free(map->text_path.so);
	free(map->text_path.we);
	free(map->text_path.ea);
	free(map->text_path.spr);
	ft_lstclear(&map->map_tmp, &free);
	ft_lstclear(&map->trash, &free);
	exit(0);
}

int				key_press(int keycode, t_map *map)
{
	if (keycode == 13)
		map->key |= KEY_W;
	else if (keycode == 1)
		map->key |= KEY_S;
	else if (keycode == 0)
		map->key |= KEY_A;
	else if (keycode == 2)
		map->key |= KEY_D;
	else if (keycode == 123)
		map->key |= KEY_LEFT;
	else if (keycode == 124)
		map->key |= KEY_RIGHT;
	else if (keycode == 53)
		map->key |= KEY_ESC;
	return (0);
}

int				key_release(int keycode, t_map *map)
{
	if (keycode == 13)
		map->key -= KEY_W;
	else if (keycode == 1)
		map->key -= KEY_S;
	else if (keycode == 0)
		map->key -= KEY_A;
	else if (keycode == 2)
		map->key -= KEY_D;
	else if (keycode == 123)
		map->key -= KEY_LEFT;
	else if (keycode == 124)
		map->key -= KEY_RIGHT;
	else if (keycode == 53)
		map->key -= KEY_ESC;
	return (0);
}

void			moves(t_map *map)
{
	if (map->key & KEY_W)
		move_forward(map);
	if (map->key & KEY_S)
		move_backward(map);
	if (map->key & KEY_A)
		move_left(map);
	if (map->key & KEY_D)
		move_right(map);
	if (map->key & KEY_RIGHT)
		rot_right(map);
	if (map->key & KEY_LEFT)
		rot_left(map);
	if (map->key & KEY_ESC)
		esc_game(map);
}

int				key_esc(void *param)
{
	ft_putstr_fd("cub3d exit\n", 2);
	(void)param;
	exit(0);
}
