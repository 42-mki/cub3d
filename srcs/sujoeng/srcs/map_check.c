/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:47:32 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:47:34 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		check_borders(t_map *map)
{
	int i;

	i = 0;
	while (i != map->x)
	{
		if (map->map[0][i] != 1)
			error_exit(map, 1);
		if (map->map[map->y - 1][i] != 1)
			error_exit(map, 1);
		i++;
	}
	i = 1;
	while (i != map->y - 1)
	{
		if (map->map[i][0] != 1)
			error_exit(map, 1);
		if (map->map[i][map->x - 1] != 1)
			error_exit(map, 1);
		i++;
	}
}

static void		check_player_pos(t_map *map, int y, int x)
{
	if (!map->check_pos)
		map->check_pos++;
	else
		error_exit(map, 1);
	map->player.pos_x = x + 0.5;
	map->player.pos_y = y + 0.5;
	if (map->map[y][x] == 'N' - '0')
		map->player.direction = 'N';
	else if (map->map[y][x] == 'E' - '0')
		map->player.direction = 'E';
	else if (map->map[y][x] == 'W' - '0')
		map->player.direction = 'W';
	else if (map->map[y][x] == 'S' - '0')
		map->player.direction = 'S';
	else
		error_exit(map, 1);
}

int				check_map(t_map *map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	check_borders(map);
	while (y != map->y)
	{
		while (x != map->x)
		{
			if (!(check_map_element(map->map[y][x] + '0', map)))
				error_exit(map, 1);
			if (map->map[y][x] > 2)
				check_player_pos(map, y, x);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
