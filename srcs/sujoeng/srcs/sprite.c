/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:48:28 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:48:30 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			sprite_loop(t_map *map)
{
	int i;

	i = 0;
	update_sprite(map);
	sort_sprite(map);
	sprite_init(map);
	while (i <= map->sprite_nb &&\
		(map->sprite[i]->map_x || map->sprite[i]->map_y))
	{
		loop_sprites(map, i);
		i++;
	}
}
