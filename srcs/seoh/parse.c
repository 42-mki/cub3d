/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 02:42:15 by seoh              #+#    #+#             */
/*   Updated: 2020/10/25 02:52:39 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*cub_read_line(const char *path)
{
	int		fd;
	char	*temp;
	char	*store;
	char	*line;
	if ((fd = open(path, O_RDONLY)) != 3)
	{
		perror(ft_strjoin("Error\n", path));
		exit(1);
	}
	store = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		temp = ft_strjoin(store, line);
		free(store);
		store = temp;
		temp = ft_strjoin(store, "\n");
		free(store);
		store = temp;
		free(line);
	}
	free(line);
	close(fd);
	return (store);
}
void		cub_read_file(t_window *window, const char *path)
{
	char	*cub_oneline;
	char	**cub_temp;
//	int		m_r_count;
//	init_cub(window->cub);
	cub_oneline = cub_read_line(path);
	cub_temp = ft_split(cub_oneline, '\n');
}
