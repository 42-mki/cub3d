/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 19:34:07 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 17:21:13 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H
# include "vector.h"
# define TEXTURE_LENGTH	5
# include "image.h"
# include "map.h"

typedef struct			s_info
{
	void				*mlx;
	void				*win;
	t_image				img;
	t_image				textures[TEXTURE_LENGTH];
	t_vector			pos;
	t_vector			dir;
	t_vector			plane;
	double				time;
	double				old_time;
	t_map				*map;
}						t_info;

void					save_player_direction(t_info *info, char c);
int						load_map(t_info *info, t_map *map, char *file);

#endif
