/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:02:39 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:46:12 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include "math.h"
#include <fcntl.h>
#include "common.h"
#include "error.h"
#include "vector.h"
#include "info.h"

void	copy_map(t_map *map, char *buf)
{
	char	*tmp;
	int		i;

	map->map = (char**)malloc(sizeof(char*) * map->shape.y);
	tmp = ft_strtok(buf, "\n");
	map->map[0] = (char*)malloc(sizeof(char) * (map->shape.x + 1));
	ft_strcpy(map->map[0], tmp);
	i = 1;
	while (i < map->shape.y)
	{
		map->map[i] = (char*)malloc(sizeof(char) * (map->shape.x + 1));
		tmp = ft_strtok(NULL, "\n");
		ft_strcpy(map->map[i], tmp);
		i++;
	}
}

int		max(int x, int y)
{
	return ((x > y) ? x : y);
}

int		load_2d_map(char *buf, t_map *map, int fd)
{
	char	*tmp;
	char	*line;

	init_vector_int(&map->shape, 0, 0);
	map->shape.y = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_valid_line(line) == FALSE)
			error();
		map->shape.x = max(map->shape.x, ft_strlen(line));
		tmp = line;
		line = ft_strjoin("\n", line);
		free(tmp);
		tmp = buf;
		buf = ft_strjoin(buf, line);
		map->shape.y++;
		free(tmp);
		free(line);
	}
	copy_map(map, buf);
	free(buf);
	save_player_loc(map);
	return (TRUE);
}

void	load_map_sub(t_map *map, char *file)
{
	int		fd;
	int		is_started;
	char	*line;

	is_started = FALSE;
	if ((fd = open(file, O_RDONLY)) == -1)
		error();
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue;
		}
		is_started = (is_map(line) ? TRUE : FALSE);
		if (!is_started)
		{
			if (parse_line(map, line) < 0)
				error();
			free(line);
		}
		else
			load_2d_map(line, map, fd);
	}
}

int		load_map(t_info *info, t_map *map, char *file)
{
	int			*visited;

	init_map(map);
	load_map_sub(map, file);
	save_player_direction(info, map->player_dir);
	visited = ft_calloc(map->shape.x * map->shape.y, sizeof(int));
	if (!is_valid_map(map, map->player.x, map->player.y, visited))
		error();
	free(visited);
	return (TRUE);
}
