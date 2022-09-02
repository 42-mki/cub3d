/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:45:41 by mki               #+#    #+#             */
/*   Updated: 2021/01/16 11:28:37 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_dir_vec(t_data *data)
{
	t_vec	end;

	end.x = data->pos.x + data->dir.x * DIR_LEN;
	end.y = data->pos.y + data->dir.y * DIR_LEN;
	ft_dda(data, data->pos, end);
}