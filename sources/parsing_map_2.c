/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:32:33 by mki               #+#    #+#             */
/*   Updated: 2021/03/10 13:07:38 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_vec(t_data *d)
{
	d->dda.dir.x = 0.0;
	d->dda.dir.y = 0.0;
	d->dda.plane.x = 0.0;
	d->dda.plane.y = 0.0;
	d->tri.sin_p = sin(M_PI * ROTATE_SPEED / 180);
	d->tri.sin_m = sin(-M_PI * ROTATE_SPEED / 180);
	d->tri.cos_p = cos(M_PI * ROTATE_SPEED / 180);
	d->tri.cos_m = cos(-M_PI * ROTATE_SPEED / 180);
	d->cub.dir = 0;
	d->cub.dir_cnt = 0;
}

int		player_direction(t_dda *dda, char c)
{
	if (c == 'N')
	{
		dda->dir.x = -1.0;
		dda->plane.y = 1;
	}
	else if (c == 'S')
	{
		dda->dir.x = 1.0;
		dda->plane.y = -1;
	}
	else if (c == 'W')
	{
		dda->dir.y = -1.0;
		dda->plane.x = -1;
	}
	else if (c == 'E')
	{
		dda->dir.y = 1.0;
		dda->plane.x = 1;
	}
	else
		return (1);
	return (0);
}
