/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:46:38 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 17:20:36 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "vector.h"

typedef struct		s_map
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*sprite_texture;
	t_vector_int	res;
	t_vector_int	player;
	t_vector_int	shape;
	char			player_dir;
	int				floor_color;
	int				ceil_color;
	char			**map;
}					t_map;

int					load_2d_map(char *buf, t_map *map, int fd);
void				load_map_sub(t_map *map, char *file);
void				copy_map(t_map *map, char *buf);
int					parse_line(t_map *map, char *line);
void				save_player_loc(t_map *map);
int					is_map(char *line);
void				init_map(t_map *map);
int					is_valid_map(t_map *map, int x, int y, int *visited);
#endif
