/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:28:42 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 16:45:18 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int key, t_data *d)
{
	if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W ||
	key == ARROW_L || key == ARROW_R || key == KEY_ESC)
		d->key_flag[key] = 1;
	return (0);
}

int		key_release(int key, t_data *d)
{
	if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W ||
	key == ARROW_L || key == ARROW_R || key == KEY_ESC)
		d->key_flag[key] = 0;
	return (0);
}

int		exit_button(t_data *d)
{
	sprites_free(&d->spr);
	exit(0);
	return (0);
}

void	init_key(t_data *data)
{
	int		i;

	i = 256;
	while (i)
		data->key_flag[--i] = 0;
	i = 4;
	while (i)
		data->wall_flag[--i] = 0;
}

void	key(t_data *d)
{
	init_key(d);
	mlx_hook(d->mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, d);
	mlx_hook(d->mlx.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_release, d);
	mlx_hook(d->mlx.win_ptr, X_EVENT_EXIT, 0, &exit_button, d);
}
