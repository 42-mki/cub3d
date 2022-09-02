/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:16:28 by mki               #+#    #+#             */
/*   Updated: 2021/03/10 18:30:11 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	count_sprites(t_data *d, t_spr *s)
{
	int		x;
	int		y;

	s->num_sprite = 0;
	x = -1;
	while (++x < d->cub.row)
	{
		y = -1;
		while (++y < d->cub.col)
			if (d->cub.world_map[x][y] == 2)
				s->num_sprite++;
	}
}

void	sprites_locate(t_data *d, t_spr *s)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = -1;
	while (++x < d->cub.row)
	{
		y = -1;
		while (++y < d->cub.col)
			if (d->cub.world_map[x][y] == 2)
			{
				s->pos[i].x = x + 0.5;
				s->pos[i].y = y + 0.5;
				i++;
			}
	}
}

int		sprites_malloc(t_spr *s)
{
	s->sprite_order = ft_calloc(s->num_sprite, sizeof(int));
	s->sprite_dist = ft_calloc(s->num_sprite, sizeof(double));
	s->pos = ft_calloc(s->num_sprite, sizeof(t_vec_d));
	return (0);
}

void	sprites_free(t_spr *s)
{
	free(s->sprite_order);
	free(s->sprite_dist);
	free(s->pos);
}
