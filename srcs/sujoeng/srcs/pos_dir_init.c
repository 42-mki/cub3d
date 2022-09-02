/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_dir_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:48:08 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:48:09 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	pos_init2(t_map *map)
{
	if (map->player.direction == 'W')
	{
		map->player.dir_x = -1;
		map->player.dir_y = 0;
		map->player.plane_x = 0;
		map->player.plane_y = -0.66;
	}
	else if (map->player.direction == 'E')
	{
		map->player.dir_x = 1;
		map->player.dir_y = 0;
		map->player.plane_x = 0;
		map->player.plane_y = 0.66;
	}
}

void		pos_init(t_map *map)
{
	if (map->player.direction == 'N')
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
		map->player.plane_x = 0.66;
		map->player.plane_y = 0;
	}
	else if (map->player.direction == 'S')
	{
		map->player.dir_x = 0;
		map->player.dir_y = 1;
		map->player.plane_x = -0.66;
		map->player.plane_y = 0;
	}
	else
		pos_init2(map);
}

int			y_distance(t_map *map, char *av)
{
	int		y;
	int		fd;
	int		ret;
	char	*line;

	y = 0;
	if (!(fd = open(av, O_RDONLY)))
		error_exit(map, 2);
	while ((ret = get_next_line(fd, &line)))
	{
		if (line[0] == '1' || line[0] == ' ')
			y++;
		ft_strdel(&line);
	}
	if (line[0] == '1' || line[0] == ' ')
		y++;
	ft_strdel(&line);
	close(fd);
	return (y);
}
