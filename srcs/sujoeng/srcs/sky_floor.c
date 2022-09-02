/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:48:18 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:48:20 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	convert_rgb(t_map *map, char *line, int fc)
{
	int r;
	int g;
	int	b;
	int i;

	i = 0;
	r = ft_atoi(line);
	while (ft_isdigit(line[i]))
		i++;
	g = ft_atoi(line + ++i);
	while (ft_isdigit(line[i]))
		i++;
	b = ft_atoi(line + ++i);
	if ((r > 0 && r <= 255) && (g > 0 && g <= 255) && (b > 0 && b <= 255))
	{
		if (!fc)
			map->color.floor = 65536 * r + 256 * g + b;
		else
			map->color.ceiling = 65536 * r + 256 * g + b;
	}
	else
		error_exit(map, 1);
}

void	sky_floor(t_map *map)
{
	int		x;
	int		sky;

	x = 0;
	if ((map->color.ceiling < 0) || (map->color.floor < 0))
		error_exit(map, 1);
	while (x < (map->win.s_l / 4) * map->res_y / 2)
	{
		map->win.str[x] = map->color.ceiling;
		x++;
	}
	while (x < (map->win.s_l / 4) * map->res_y)
	{
		map->win.str[x] = map->color.floor;
		x++;
	}
}

int		open_error(char **av)
{
	int fd;

	if ((fd = open(av[1], O_WRONLY) < 0))
	{
		ft_putstr_fd("error : not file", 2);
		close(fd);
		return (0);
	}
	return (1);
}
