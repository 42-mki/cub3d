/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 02:30:02 by mki               #+#    #+#             */
/*   Updated: 2021/01/31 14:51:32 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*find_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

static int	line_split(char *index, char **line, char **one)
{
	char	*tmp;

	if (index)
	{
		*index = '\0';
		*line = ft_strdup(*one);
		tmp = ft_strdup(index + 1);
		free(*one);
		*one = tmp;
		return (1);
	}
	*line = ft_strdup(*one);
	free(*one);
	*one = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*one[OPEN_MAX];
	char		*index;
	char		*buf;
	int			ret;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!one[fd])
		one[fd] = ft_strdup("");
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!(index = find_line(one[fd]))
	&& (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		index = ft_strjoin(one[fd], buf);
		free(one[fd]);
		one[fd] = index;
	}
	free(buf);
	if (ret < 0)
		return (-1);
	return (line_split(index, line, &one[fd]));
}
