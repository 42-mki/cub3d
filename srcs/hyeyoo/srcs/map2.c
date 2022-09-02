/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:40:56 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:33:08 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "map.h"
#include "vector.h"
#include "libft.h"
#include "error.h"

int		parse_line_sub(t_map *map, char *token)
{
	if (ft_strcmp(token, "R") == 0)
	{
		map->res.x = ft_atoi(ft_strtok(NULL, " "));
		map->res.x = (map->res.x > 2560) ? 2560 : map->res.x;
		map->res.y = ft_atoi(ft_strtok(NULL, " "));
		map->res.y = (map->res.y > 1440) ? 1440 : map->res.y;
	}
	else if (ft_strcmp(token, "NO") == 0)
		map->north_texture = ft_strdup(ft_strtok(NULL, " "));
	else if (ft_strcmp(token, "SO") == 0)
		map->south_texture = ft_strdup(ft_strtok(NULL, " "));
	else if (ft_strcmp(token, "EA") == 0)
		map->east_texture = ft_strdup(ft_strtok(NULL, " "));
	else if (ft_strcmp(token, "WE") == 0)
		map->west_texture = ft_strdup(ft_strtok(NULL, " "));
	else if (ft_strcmp(token, "S") == 0)
		map->sprite_texture = ft_strdup(ft_strtok(NULL, " "));
	else
		return (FALSE);
	return (TRUE);
}

int		make_rgb(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}

int		parse_line(t_map *map, char *line)
{
	char	*token;

	if ((token = ft_strtok(line, " ")) == NULL)
		return (FALSE);
	else if (parse_line_sub(map, token) == TRUE)
		return (TRUE);
	else if (ft_strcmp(token, "F") == 0)
	{
		map->floor_color = make_rgb(ft_atoi(ft_strtok(NULL, ",")), \
					ft_atoi(ft_strtok(NULL, ",")), \
					ft_atoi(ft_strtok(NULL, ",")));
	}
	else if (ft_strcmp(token, "C") == 0)
	{
		map->ceil_color = make_rgb(ft_atoi(ft_strtok(NULL, ",")), \
					ft_atoi(ft_strtok(NULL, ",")), \
					ft_atoi(ft_strtok(NULL, ",")));
	}
	else
		return (FALSE);
	return (TRUE);
}

int		is_ewsn(char c)
{
	return (c == 'E' || c == 'W' || c == 'S' || c == 'N');
}

void	save_player_loc(t_map *map)
{
	int		x;
	int		y;
	int		found;

	y = 0;
	found = FALSE;
	while (y < map->shape.y)
	{
		x = 0;
		while (x < map->shape.x && map->map[y][x] != '\0')
		{
			if (is_ewsn(map->map[y][x]))
			{
				if (found)
					error();
				found = TRUE;
				init_vector_int(&map->player, x, y);
				map->player_dir = map->map[y][x];
			}
			x++;
		}
		y++;
	}
	if (found == FALSE)
		error();
}
