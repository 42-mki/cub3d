/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:37:55 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 17:21:20 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H
# include "map.h"
# include "info.h"

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

void			load_sprites(t_info *info, t_sprite *sprites);
int				number_of_sprites(t_map *map);
void			sort_sprites(t_sprite *sprites, int size);

#endif
