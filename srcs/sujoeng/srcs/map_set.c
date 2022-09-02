/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:47:44 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:47:46 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	define_tex(char *line, t_map *map, char flag)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	flag == 'N' ? map->text_path.no = ft_strdup(line + i) : 0;
	flag == 'S' ? map->text_path.so = ft_strdup(line + i) : 0;
	flag == 'W' ? map->text_path.we = ft_strdup(line + i) : 0;
	flag == 'E' ? map->text_path.ea = ft_strdup(line + i) : 0;
	flag == 's' ? map->text_path.spr = ft_strdup(line + i) : 0;
	flag == 'F' ? convert_rgb(map, line + i, 0) : 0;
	flag == 'C' ? convert_rgb(map, line + i, 1) : 0;
}

static void	define_res(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == 'R')
		i++;
	map->res_x = ft_atoi(line + i);
	if (map->res_x > 2560)
		map->res_x = 2560;
	while (ft_isdigit(line[i]))
		i++;
	map->res_y = ft_atoi(line + i);
	if (map->res_y > 1440)
		map->res_y = 1440;
	if (map->res_x <= 0 || map->res_y <= 0)
		error_exit(map, 1);
}

static void	define_flag(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	line[i] == 'R' && line[i + 1] == ' ' ? \
	define_res(line, map) : 0;
	line[i] == 'N' && line[i + 1] == 'O' ? \
	define_tex(line + i + 2, map, 'N') : 0;
	line[i] == 'S' && line[i + 1] == 'O' ? \
	define_tex(line + i + 2, map, 'S') : 0;
	line[i] == 'W' && line[i + 1] == 'E' ? \
	define_tex(line + i + 2, map, 'W') : 0;
	line[i] == 'E' && line[i + 1] == 'A' ? \
	define_tex(line + i + 2, map, 'E') : 0;
	line[i] == 'S' && line[i + 1] != 'O' ? \
	define_tex(line + i + 1, map, 's') : 0;
	line[i] == 'F' ? define_tex(line + i + 1, map, 'F') : 0;
	line[i] == 'C' ? define_tex(line + i + 1, map, 'C') : 0;
}

static void	init_loop(char *line, t_map *map, char **tmp)
{
	int	i;

	i = 0;
	if (ft_char(line[i], FLAGS))
		define_flag(line, map);
	if (line[0] == '1' || line[0] == ' ')
	{
		tmp[map->idx] = ft_strdup(line);
		map->idx++;
		map->y++;
	}
}

int			map_init(char *av, t_map *map)
{
	char	*line;
	int		ret;
	int		fd;
	char	**tmp;

	line = NULL;
	map->idx = 0;
	lst_malloc((void **)&tmp, y_distance(map, av) *\
	sizeof(int *), map);
	if (!(fd = open(av, O_RDONLY)))
		return (0);
	while ((ret = get_next_line(fd, &line)))
	{
		init_loop(line, map, tmp);
		ft_strdel(&line);
	}
	if (line[0] == '1' || line[0] == ' ')
	{
		tmp[map->idx] = ft_strdup(line);
		map->y++;
	}
	ft_strdel(&line);
	close(fd);
	map_parse(map, tmp);
	return (check_map(map));
}
