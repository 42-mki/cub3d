/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:48:20 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:37:55 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common.h"
#include "map.h"
#include "math.h"
#include "error.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		is_map(char *line)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' '
				&& !is_ewsn(line[i]) && line[i] != '2')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	init_map(t_map *map)
{
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->sprite_texture = NULL;
	map->res.x = -1;
	map->res.y = -1;
	map->floor_color = -1;
	map->ceil_color = -1;
}

int		is_valid_option(t_map *map)
{
	if (map->north_texture == NULL | map->south_texture == NULL)
		return (FALSE);
	else if (map->east_texture == NULL | map->west_texture == NULL)
		return (FALSE);
	else if (map->res.x <= 0 || map->res.y <= 0)
		return (FALSE);
	else if (map->floor_color <= 0 || map->ceil_color <= 0)
		return (FALSE);
	else if (map->sprite_texture == NULL)
		return (FALSE);
	else
		return (TRUE);
}

int		is_valid_map(t_map *map, int x, int y, int *visited)
{
	int				*dx;
	int				*dy;
	int				i;
	t_vector_int	to;

	if (x <= 0 || x >= map->shape.x - 1 || y <= 0 || y >= map->shape.y - 1)
		return (FALSE);
	visited[y * map->shape.x + x] = TRUE;
	dx = (int[4]){1, -1, 0, 0};
	dy = (int[4]){0, 0, -1, 1};
	i = 0;
	while (i < 4)
	{
		init_vector_int(&to, x + dx[i], y + dy[i]);
		if (0 <= to.x && to.x < map->shape.x && 0 <= to.y
		&& to.y < map->shape.y && map->map[to.y][to.x] != '1'
		&& !visited[to.y * map->shape.x + to.x])
		{
			if (!is_valid_map(map, to.x, to.y, visited))
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
