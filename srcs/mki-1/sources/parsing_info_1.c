/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:32:29 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 15:14:29 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	content_trim(t_list *lst)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		lst->content = ft_strtrim(lst->content, " ");
		lst = lst->next;
	}
}

int		find_word(t_data *d, char **split_val, int len)
{
	int		res;

	res = 0;
	len = ft_strlen(split_val[0]);
	if (!(ft_strncmp(split_val[0], "R", len)))
		res = parsing_res(d, split_val);
	else if (!(ft_strncmp(split_val[0], "S", len)))
		res = parsing_tex(&d->tex.path[4], split_val);
	else if (!(ft_strncmp(split_val[0], "NO", len)))
		res = parsing_tex(&d->tex.path[3], split_val);
	else if (!(ft_strncmp(split_val[0], "SO", len)))
		res = parsing_tex(&d->tex.path[2], split_val);
	else if (!(ft_strncmp(split_val[0], "WE", len)))
		res = parsing_tex(&d->tex.path[1], split_val);
	else if (!(ft_strncmp(split_val[0], "EA", len)))
		res = parsing_tex(&d->tex.path[0], split_val);
	else if (!(ft_strncmp(split_val[0], "F", len)))
		res = parsing_fc(split_val, &d->cub.floor);
	else if (!(ft_strncmp(split_val[0], "C", len)))
		res = parsing_fc(split_val, &d->cub.ceiling);
	else
		return (1);
	return (res);
}

int		parsing_info(t_data *d, t_list *lst_begin)
{
	int		i;
	char	c;
	char	**split_val;
	t_list	*lst;
	int		len;

	lst = lst_begin;
	i = -1;
	len = 0;
	while (++i < 8)
	{
		c = *(char *)lst->content;
		if (c == 'C' || c == 'F')
			split_val = ft_split_bonus(lst->content, " ,");
		else
			split_val = ft_split(lst->content, ' ');
		if (find_word(d, split_val, len))
			return (1);
		free(split_val);
		lst = lst->next;
	}
	d->par.map_begin = lst;
	return (0);
}
