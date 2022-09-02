/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 03:32:41 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 15:13:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		wall_check(t_cub *cub, int x, int y, int dir)
{
	while ((0 <= y) && (y < cub->col) && (0 <= x) && (x < cub->row))
	{
		if (cub->world_map[x][y] == 1)
			break ;
		else if (cub->world_map[x][y] == 0 || cub->world_map[x][y] == 2)
		{
			if (dir == LEFT)
				y--;
			else if (dir == RIGHT)
				y++;
			else if (dir == UP)
				x--;
			else if (dir == DOWN)
				x++;
		}
		else
			return (1);
	}
	return (0);
}

int		map_is_valid(t_cub *cub, int **map)
{
	int		x;
	int		y;

	x = -1;
	while (++x < cub->row)
	{
		y = -1;
		while (++y < cub->col)
			if (map[x][y] == 0 || map[x][y] == 2)
			{
				if (wall_check(cub, x, y + 1, RIGHT))
					return (1);
				if (wall_check(cub, x, y - 1, LEFT))
					return (1);
				if (wall_check(cub, x - 1, y, UP))
					return (1);
				if (wall_check(cub, x + 1, y, DOWN))
					return (1);
			}
	}
	return (0);
}
