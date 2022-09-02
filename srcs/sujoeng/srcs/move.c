/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:48:02 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:48:04 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		move_forward(t_map *map)
{
	int horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x + map->player.dir_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y + map->player.dir_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x += map->player.dir_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y += map->player.dir_y * 0.08;
}

void		move_backward(t_map *map)
{
	int	horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x - map->player.dir_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y - map->player.dir_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x -= map->player.dir_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y -= map->player.dir_y * 0.08;
}

void		move_left(t_map *map)
{
	int	horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x - map->player.plane_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y - map->player.plane_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x -= map->player.plane_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y -= map->player.plane_y * 0.08;
}

void		move_right(t_map *map)
{
	int	horizontal;
	int vertical;

	horizontal = map->map[(int)map->player.pos_y]\
		[(int)(map->player.pos_x + map->player.plane_x * 0.08)];
	vertical = map->map[(int)(map->player.pos_y + map->player.plane_y * 0.08)]\
		[(int)map->player.pos_x];
	if (horizontal == 0 || horizontal > 2)
		map->player.pos_x += map->player.plane_x * 0.08;
	if (vertical == 0 || vertical > 2)
		map->player.pos_y += map->player.plane_y * 0.08;
}
