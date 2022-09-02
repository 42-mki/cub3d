/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:38:05 by mki               #+#    #+#             */
/*   Updated: 2021/01/18 11:38:30 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rotate(t_data *data)
{
	if (data->key_flag[ARROW_L])
	{
		data->dir = ft_rotate_vec(data->dir, data->pai, LEFT);
		data->plane = ft_rotate_vec(data->plane, data->pai, LEFT);
	}
	if (data->key_flag[ARROW_R])
	{
		data->dir = ft_rotate_vec(data->dir, data->pai, RIGHT);
		data->plane = ft_rotate_vec(data->plane, data->pai, RIGHT);
	}
}