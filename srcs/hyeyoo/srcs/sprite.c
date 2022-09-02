/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:39:55 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 17:05:01 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "common.h"
#include "sprite.h"
#include "info.h"
#include "math.h"

int		number_of_sprites(t_map *map)
{
	int		ans;
	int		x;
	int		y;

	ans = 0;
	y = 0;
	while (y < map->shape.y)
	{
		x = 0;
		while (x < map->shape.x)
		{
			if (map->map[y][x] == SPRITE)
			{
				ans++;
			}
			x++;
		}
		y++;
	}
	return (ans);
}

void	load_sprites(t_info *info, t_sprite *sprites)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (y < info->map->shape.y)
	{
		x = 0;
		while (x < info->map->shape.x)
		{
			if (info->map->map[y][x] == SPRITE)
			{
				sprites[i].x = (double)x;
				sprites[i].y = (double)y;
				sprites[i].dist = pow(info->pos.x - sprites[i].x, 2) +\
									pow(info->pos.y - sprites[i].y, 2);
				i++;
			}
			x++;
		}
		y++;
	}
}

void	sort_sprites(t_sprite *sprites, int size)
{
	int			i;
	int			j;
	t_sprite	tmp;
	int			max_idx;

	i = 0;
	while (i < size - 1)
	{
		max_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (sprites[i].dist > sprites[max_idx].dist)
				max_idx = j;
			j++;
		}
		tmp = sprites[i];
		sprites[i] = sprites[max_idx];
		sprites[max_idx] = tmp;
		i++;
	}
}
