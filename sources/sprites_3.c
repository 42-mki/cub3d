/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:16:28 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 15:18:23 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_sprites(t_data *d, t_spr *s)
{
	s->stripe = s->draw_start.x - 1;
	while (++s->stripe < s->draw_end.x)
	{
		s->tex.x = (int)((256 * (s->stripe - (-s->width / 2 + s->screen_x))
		* TEX_WIDTH / s->width) / 256);
		s->y = s->draw_start.y - 1;
		if (s->tf.y > 0 && s->stripe > 0 && s->stripe < d->cub.width
		&& s->tf.y < d->dda.buffer[s->stripe])
			while (++s->y < s->draw_end.y)
			{
				s->d = (s->y - s->v_move_screen) * 256 - d->cub.height * 128
				+ s->height * 128;
				s->tex.y = ((s->d * TEX_HEIGHT) / s->height) / 256;
				s->color = d->texture[4][TEX_WIDTH * s->tex.y + s->tex.x];
				if ((s->color & 0x00FFFFFF) != 0)
					pixel_put(d, s->stripe, s->y, s->color);
			}
	}
}

void	processing_sprites(t_dda *d, t_cub *c, t_spr *s, int i)
{
	s->sprite.x = s->pos[s->sprite_order[i]].x - d->pos.x;
	s->sprite.y = s->pos[s->sprite_order[i]].y - d->pos.y;
	s->det = 1.0 / (d->plane.x * d->dir.y - d->dir.x * d->plane.y);
	s->tf.x = s->det * (d->dir.y * s->sprite.x - d->dir.x * s->sprite.y);
	s->tf.y = s->det * (-d->plane.y * s->sprite.x + d->plane.x * s->sprite.y);
	s->screen_x = (int)((c->width / 2) * (1 + s->tf.x / s->tf.y));
	s->height = (int)fabs(c->height / s->tf.y);
	s->draw_start.y = -s->height / 2 + c->height / 2;
	if (s->draw_start.y < 0)
		s->draw_start.y = 0;
	s->draw_end.y = s->height / 2 + c->height / 2;
	if (s->draw_end.y >= c->height)
		s->draw_end.y = c->height - 1;
	s->width = (int)fabs(c->height / s->tf.y);
	s->draw_start.x = -s->width / 2 + s->screen_x;
	if (s->draw_start.x < 0)
		s->draw_start.x = 0;
	s->draw_end.x = s->width / 2 + s->screen_x;
	if (s->draw_end.x >= c->width)
		s->draw_end.x = c->width - 1;
}

void	calc_sprites(t_data *d, t_spr *s)
{
	int		i;

	i = -1;
	while (++i < s->num_sprite)
	{
		processing_sprites(&d->dda, &d->cub, s, i);
		put_sprites(d, s);
	}
}
