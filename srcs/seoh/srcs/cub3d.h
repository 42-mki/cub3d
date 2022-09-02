/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 06:31:21 by seoh              #+#    #+#             */
/*   Updated: 2020/10/25 06:36:49 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/libft/libft.h"

typedef struct	s_player
{
	int			x;
	int			y;
	int			color;
}				t_player;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	t_player	player;

	int			width;
	int			height;

	int			row_count;
	int			column_count;
	int			grid_color;
}				t_window;

typedef struct	s_mapdata
{
	int		r_width;
	int		r_height;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	char	*sprite;
	int		f;
	int		c;
	
	char	**map;
}				t_mapdata;

int				press_key_for_dot(int key, t_window *window);
