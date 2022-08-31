/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:32:29 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 16:04:31 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		len_check(char *s, int num)
{
	int		len;

	len = ft_strlen(s);
	if (len > num)
		return (1);
	return (0);
}

int		parsing_res(t_data *d, char **s)
{
	int		width;
	int		height;

	if (!s[1] || !s[2] || s[3])
		return (1);
	if (len_check(s[1], 9))
		return (1);
	if (len_check(s[2], 9))
		return (1);
	d->cub.width = ft_atoi(s[1]);
	d->cub.height = ft_atoi(s[2]);
	d->dda.buffer = (double *)malloc(sizeof(double) * d->cub.width);
	mlx_get_screen_size(d->mlx.mlx_ptr, &width, &height);
	if (d->cub.width > width)
		d->cub.width = width;
	if (d->cub.height > height)
		d->cub.height = height;
	free(s[0]);
	free(s[1]);
	free(s[2]);
	return (0);
}

int		parsing_tex(char **d, char **s)
{
	if (!s[1] || s[2])
		return (1);
	*d = s[1];
	free(s[0]);
	return (0);
}

int		parsing_fc_error(char **s)
{
	int		num;

	if (!s[1] || !s[2] || !s[3] || s[4])
		return (1);
	if (len_check(s[1], 3))
		return (1);
	if (len_check(s[2], 3))
		return (1);
	if (len_check(s[3], 3))
		return (1);
	num = ft_atoi(s[1]);
	if (0 > num || num > 255)
		return (1);
	num = ft_atoi(s[2]);
	if (0 > num || num > 255)
		return (1);
	num = ft_atoi(s[3]);
	if (0 > num || num > 255)
		return (1);
	return (0);
}

int		parsing_fc(char **s, int *value)
{
	int		num;

	if (parsing_fc_error(s))
		return (1);
	*value = 0;
	num = ft_atoi(s[1]);
	*value += num;
	*value <<= 8;
	num = ft_atoi(s[2]);
	*value += num;
	*value <<= 8;
	num = ft_atoi(s[3]);
	*value += num;
	free(s[0]);
	free(s[1]);
	free(s[2]);
	free(s[3]);
	return (0);
}
