/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:29:18 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 15:58:34 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	add_back(t_par *p)
{
	ft_lstadd_back(&p->lst, ft_lstnew(p->get_line));
	p->line_cnt++;
}

int		open_cub(t_par *p)
{
	int		gnl;

	p->fd = open(p->file, O_RDONLY);
	if (p->fd < 3)
		return (1);
	if (get_next_line(p->fd, &p->get_line) < 0)
		return (1);
	p->lst_begin = ft_lstnew(p->get_line);
	p->lst = p->lst_begin;
	while ((gnl = get_next_line(p->fd, &p->get_line)))
	{
		if (gnl < 0)
			return (1);
		if (p->line_cnt < 8 && *(char *)p->get_line != '\0')
			add_back(p);
		else if (p->line_cnt >= 8)
			add_back(p);
	}
	add_back(p);
	return (0);
}

int		parsing(t_data *d)
{
	d->par.line_cnt = 1;
	if (open_cub(&d->par))
		return (1);
	if (parsing_info(d, d->par.lst_begin))
		return (1);
	if (parsing_map(d))
		return (1);
	return (0);
}
