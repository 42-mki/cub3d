/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:47:25 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:47:27 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		mlx_setting(t_map *map)
{
	if (!(map->win.mlx_ptr = mlx_init()))
		return (0);
	if (!(map->win.mlx_win = mlx_new_window(map->win.mlx_ptr,\
		map->res_x, map->res_y, "cub3D")))
		return (0);
	return (0);
}

static void		init(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->res_x = 0;
	map->res_y = 0;
	map->check_x = 1;
	map->check_pos = 0;
	map->player.dir_x = -1.0;
	map->player.dir_y = 0;
	map->player.pos_x = 0;
	map->player.pos_y = 0;
	map->player.plane_x = 0;
	map->player.plane_y = 0.66;
	map->texture[0].img = NULL;
	map->texture[1].img = NULL;
	map->texture[2].img = NULL;
	map->texture[3].img = NULL;
	map->texture[4].img = NULL;
	map->player.hit = 0;
	map->player.perpwall_dist = 0;
	map->key = 0;
	map->sprite_nb = 0;
	map->color.floor = -1;
	map->color.ceiling = -1;
}

static int		cub3d_start(int ac, char **av, t_map *map)
{
	if (ac == 2)
		main_cub3d(map, 0);
	if (ac == 3 && !ft_strncmp(av[2], "--save", 7))
	{
		map = ft_calloc(1, sizeof(t_map));
		init(map);
		map_init(av[1], map);
		mlx_setting(map);
		map->win.mlx_img = mlx_new_image(map->win.mlx_ptr,\
		map->res_x, map->res_y);
		if (!(map->win.str = (unsigned int *)mlx_get_data_addr(\
		map->win.mlx_img, &map->win.b_p, &map->win.s_l, &map->win.endian)))
			error_exit(map, 2);
		main_cub3d(map, 1);
		export_bmp("screenshot.bmp", (char *)map->win.str,
			map->res_x, map->res_y);
		error_exit(map, 0);
	}
	else if (ac == 3)
		ft_putstr_fd("error : not --save option\n", 2);
	return (0);
}

static void		cub3d_ready(t_map *map, char **av, int ac)
{
	map = ft_calloc(1, sizeof(t_map));
	init(map);
	map_init(av[1], map);
	mlx_setting(map);
	cub3d_start(ac, av, map);
}

int				main(int ac, char **av)
{
	t_map	*map;
	int		j;

	j = 0;
	if (open_error(av) == 0)
		exit(0);
	while (av[1][j] != '.')
		j++;
	if (ac == 2 && !ft_strncmp(av[1] + j, ".cub", 4))
		cub3d_ready(map, av, ac);
	else if (ac == 3 && !ft_strncmp(av[1] + j, ".cub", 4))
		cub3d_start(ac, av, map);
	else if (ac > 3)
		ft_putstr_fd("error : many arguments\n", 2);
	else if (ft_strncmp(av[1] + j, ".cub", 4))
		ft_putstr_fd("error : not a .cub\n", 2);
	else
		ft_putstr_fd("error\n", 2);
	return (0);
}
