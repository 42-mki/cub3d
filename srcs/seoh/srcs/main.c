/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:06:05 by seoh              #+#    #+#             */
/*   Updated: 2020/10/25 07:19:09 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx/mlx.h"
#include "cub3d.h"

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

void	init_mapdata(t_mapdata *mapdata)
{
	mapdata->r_width = 0;
	mapdata->r_height = 0;

	mapdata->no = 0;
	mapdata->so = 0;
	mapdata->we = 0;
	mapdata->ea = 0;

	mapdata->sprite = 0;
	mapdata->f = 0;
	mapdata->c = 0;
}

int		draw_grid(t_window *window)
{
	int	draw_position;
	int	i;

	i = 1;
	while (i< window->row_count)
	{
		draw_position = 0;
		while (draw_position <= window->width){
			mlx_pixel_put(window->mlx, window->win, draw_position, i * (window->height / window->row_count),window->grid_color);
			draw_position++;
		}
		i++;
	}
	i = 1;
	while (i< window->column_count)
	{
		draw_position = 0;
		while (draw_position <= window->width){
			mlx_pixel_put(window->mlx, window->win, i * (window->width/ window->column_count), draw_position,window->grid_color);
			draw_position++;
		}
		i++;
	}
	return (0);
}
void	init_player(t_window *window)
{
	mlx_pixel_put(window->mlx, window->win, window->player.x, window->player.y, window->player.color);
}

void	move_dot_left(t_window *window)
{
	int	old_x = window->player.x;
	int old_y = window->player.y;
	int	black = 0x000000;
	if ((0 < window->player.x && window->player.x <= window->width) &&
		(0 < window->player.y && window->player.x <= window->height))
	{
		//draw old spot with black first
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(window->mlx, window->win, --window->player.x, window->player.y, window->player.color);
	}
}

void	move_dot_right(t_window *window)
{
	int	old_x = window->player.x;
	int old_y = window->player.y;
	int	black = 0x000000;
	if ((0 < window->player.x && window->player.x <= window->width) &&
		(0 < window->player.y && window->player.x <= window->height))
	{
		//draw old spot with black first
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(window->mlx, window->win, ++window->player.x, window->player.y, window->player.color);
	}
}
void	move_dot_up(t_window *window)
{
	int	old_x = window->player.x;
	int old_y = window->player.y;
	int	black = 0x000000;
	if ((0 < window->player.x && window->player.x <= window->width) &&
		(0 < window->player.y && window->player.x <= window->height))
	{
		//draw old spot with black first
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(window->mlx, window->win, window->player.x, --window->player.y, window->player.color);
	}
}
void	move_dot_down(t_window *window)
{
	int	old_x = window->player.x;
	int old_y = window->player.y;
	int	black = 0x000000;
	if ((0 < window->player.x && window->player.x <= window->width) &&
		(0 < window->player.y && window->player.x <= window->height))
	{
		//draw old spot with black first
		mlx_pixel_put(window->mlx, window->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(window->mlx, window->win, window->player.x, ++window->player.y, window->player.color);
	}
}
int		press_key_for_dot(int key, t_window *window)
{
	if (key == KEY_A)
		move_dot_left(window);
	else if (key == KEY_D)
		move_dot_right(window);
	else if (key == KEY_W)
		move_dot_up(window);
	else if (key == KEY_S)
		move_dot_down(window);
	return (0);
}

char		*cub_read_line(const char *path)
{
	int		fd;
	char	*temp;
	char	*store;
	char	*line;
	if ((fd = open(path, O_RDONLY)) != 3)
	{
		perror(ft_strjoin("Error\n", path));
		exit(1);
	}
	store = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		temp = ft_strjoin(store, line);
		free(store);
		store = temp;
		temp = ft_strjoin(store, "\n");
		
		free(store);
		store = temp;
		free(line);
	}
	free(line);
	close(fd);
	return (store);
}
void		readmap(const char *path, t_mapdata *mapdata)
{
	char	*cub_oneline;
	char	**temp;
	int		i;
	char	**splited;

	cub_oneline = cub_read_line(path);
	temp = ft_split(cub_oneline, '\n');
	
	i = 0;
	while(i < 8)
	{
		splited = ft_split(temp[i], ' ');
		printf("%s\n", splited[1]);
		if (ft_strchr(splited[0], 'R'))
		{
			mapdata->r_width = ft_atoi(splited[1]);
			mapdata->r_height = ft_atoi(splited[2]);	
		}
		else if (ft_strchr(splited[0], 'N'))
			mapdata->no = splited[1];
		else if (ft_strchr(splited[0], 'S') && ft_strlen(splited[0]) > 1)
			mapdata->so = splited[1];
		else if (ft_strchr(splited[0], 'W'))
			mapdata->we = splited[1];
		else if (ft_strchr(splited[0], 'E'))
			mapdata->ea = splited[1];
		else if (ft_strchr(splited[0], 'S'))
			mapdata->sprite = splited[1];
		i++;
	}
	
}

int		main()
{
	// t_window window;
	// /////////////////////////////////////
	// window.width = 700;
	// window.height = 700;
	// window.row_count = 10;
	// window.column_count = 10;
	// window.grid_color = 0x00FFFF;
	// /////////////////////////////////////
	// window.player.color = 0xFF0000;
	// window.player.x = 220;
	// window.player.y = 220;
	// window.mlx = mlx_init();
	// window.win = mlx_new_window(window.mlx, window.width, window.height, "mlx_grid");
	// init_player(&window);
	// mlx_loop_hook(window.mlx, draw_grid, &window);
	// mlx_hook(window.win, 2, 1, press_key_for_dot, &window);
	// mlx_loop(window.mlx);

	t_mapdata	*mapdata;

	if (!(mapdata = (t_mapdata *)malloc(sizeof(t_mapdata))))
		return (0);

	readmap("./maps/test.cub", mapdata);
	
	printf("##%d##\n", mapdata->r_width);
	printf("##%d##\n", mapdata->r_height);
	printf("##%s##\n", mapdata->no);
	printf("##%s##\n", mapdata->so);
	printf("##%s##\n", mapdata->we);
	printf("##%s##\n", mapdata->ea);
	printf("##%s##\n", mapdata->sprite);
	
}