/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:20:05 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:46:34 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common.h"
#include "info.h"
#include "vector.h"

void	save_player_direction(t_info *info, char c)
{
	if (c == 'N')
	{
		init_vector(&info->dir, 0, -1);
		init_vector(&info->plane, 0.66, 0);
	}
	else if (c == 'S')
	{
		init_vector(&info->dir, 0, 1);
		init_vector(&info->plane, 0.66, 0);
	}
	else if (c == 'E')
	{
		init_vector(&info->dir, 1, 0);
		init_vector(&info->plane, 0, 0.66);
	}
	else if (c == 'W')
	{
		init_vector(&info->dir, -1, 0);
		init_vector(&info->plane, 0, 0.66);
	}
}

int		is_valid_line(char *line)
{
	int		len;
	int		i;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (line[i] != '0' && line[i] != '1'
				&& line[i] != '2' && line[i] != ' ' && !is_ewsn(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
