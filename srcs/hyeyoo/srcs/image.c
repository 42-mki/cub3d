/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:26:19 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 14:15:12 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "setting.h"
#include "image.h"

void	clear(t_image *img)
{
	int		x;
	int		y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			img->data[y * WINDOW_WIDTH + x] = COLOR_BLACK;
			x++;
		}
		y++;
	}
}
