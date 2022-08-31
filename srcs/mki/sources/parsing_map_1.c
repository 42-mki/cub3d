/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:32:33 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 15:55:15 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_col(t_par *p)
{
	t_list	*lst;
	int		len;
	int		max;

	lst = p->map_begin;
	len = 0;
	max = 0;
	while (lst)
	{
		len = ft_strlen(lst->content);
		if (max < len)
			max = len;
		lst = lst->next;
	}
	return (max);
}

void	init_map(int *world_map, int col)
{
	int		i;

	i = -1;
	while (++i < col)
		world_map[i] = -1;
}

int		put_map(t_data *d, char c, int i, int j)
{
	if (c == ' ')
		d->cub.world_map[i][j] = ' ';
	else if (c == '1')
		d->cub.world_map[i][j] = 1;
	else if (c == '2')
		d->cub.world_map[i][j] = 2;
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		d->cub.world_map[i][j] = 0;
		d->cub.dir = c;
		d->dda.pos.x = i + 0.3;
		d->dda.pos.y = j + 0.3;
		d->cub.dir_cnt++;
	}
	else if (c == '0')
		d->cub.world_map[i][j] = 0;
	else
		return (1);
	return (0);
}

int		get_map(t_data *d, t_cub *c, t_par *p)
{
	t_list	*lst;
	int		i;
	int		j;
	int		len;

	c->row = p->line_cnt - 8;
	c->world_map = (int **)malloc(sizeof(int *) * c->row);
	c->col = get_col(p);
	i = 0;
	lst = p->map_begin;
	while (lst)
	{
		len = ft_strlen(lst->content);
		c->world_map[i] = (int *)malloc(sizeof(int) * c->col);
		init_map(c->world_map[i], c->col);
		j = -1;
		while (++j < len)
			if (put_map(d, ((char *)lst->content)[j], i, j))
				return (1);
		i++;
		lst = lst->next;
	}
	return (0);
}

int		parsing_map(t_data *d)
{
	init_vec(d);
	if (get_map(d, &d->cub, &d->par))
		return (1);
	if (player_direction(&d->dda, d->cub.dir))
		return (1);
	if (d->cub.dir_cnt > 1)
		return (1);
	if (map_is_valid(&d->cub, d->cub.world_map))
		return (1);
	return (0);
}
