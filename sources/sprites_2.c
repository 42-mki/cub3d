/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:16:28 by mki               #+#    #+#             */
/*   Updated: 2021/03/03 23:58:04 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sort_sprites(t_spr *s)
{
	int		i;
	int		j;
	double	tmp_d;
	int		tmp_i;

	i = -1;
	while (++i < s->num_sprite - 1)
	{
		j = i;
		while (++j < s->num_sprite)
			if (s->sprite_dist[j] > s->sprite_dist[i])
			{
				tmp_d = s->sprite_dist[i];
				s->sprite_dist[i] = s->sprite_dist[j];
				s->sprite_dist[j] = tmp_d;
				tmp_i = s->sprite_order[i];
				s->sprite_order[i] = s->sprite_order[j];
				s->sprite_order[j] = tmp_i;
			}
	}
}

void	cast_sprites(t_data *d, t_spr *s)
{
	int		i;
	double	x;
	double	y;

	i = -1;
	while (++i < s->num_sprite)
	{
		s->sprite_order[i] = i;
		x = d->dda.pos.x - s->pos[i].x;
		y = d->dda.pos.y - s->pos[i].y;
		s->sprite_dist[i] = x * x + y * y;
	}
}

void	sprites(t_data *d, t_spr *s)
{
	cast_sprites(d, s);
	sort_sprites(s);
	calc_sprites(d, s);
}
