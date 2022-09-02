/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:28:42 by mki               #+#    #+#             */
/*   Updated: 2021/01/06 20:57:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_key_press(int key, t_data *data)
{
	data->key_flag[key] = 1;
	return (0);
}

int		ft_key_release(int key, t_data *data)
{
	data->key_flag[key] = 0;
	return (0);
}

int		ft_exit_button(void)
{
	exit(0);
	return (0);
}
