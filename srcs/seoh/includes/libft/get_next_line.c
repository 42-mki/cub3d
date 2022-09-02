/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:02:14 by seoh              #+#    #+#             */
/*   Updated: 2020/10/25 06:19:48 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - GNL 함수를 loop 안에서 호출하면 fd의 텍스트를 EOF가 올 때 까지 한 번에 한 줄씩 읽을 수 있다.
** - GNL 함수를 처음 호출 했을 때 파일을 끝까지 읽었다 하더라도, 두 번째 호출했을 때는 두 번째 line부터 시작해야한다.
** - file로부터, redirection으로부터, stdin으로부터 읽었을 때 함수가 제대로 동작해야 함
** - BUFFER_SIZE가 1일 때도, 9999일 때도, 10000000 (1000만)일 때도 제대로 동작해야 함
*/

char				*ft_clean_line(char *save, char **line, int r)
{
	unsigned int	i;
	char			*tmp;
	i = 0;
	while (*(save + i))
	{
		if (*(save + i) == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (r == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}
char				*ft_save_buffer(char *buffer, char *save)
{
	char			*store;
	if (save)
	{
		store = ft_strjoin(save, buffer);
		free(save);
		save = ft_strdup(store);
		free(store);
	}
	else
		save = ft_strdup(buffer);
	return (save);
}
int					get_next_line(int fd, char **line)
{
	static char		*storage[OPEN_MAX];
	char			buffer[BUFFER_SIZE + 1];
	int				result;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((result = read(fd, buffer, BUFFER_SIZE)))
	{
		if (result == -1)
			return (-1);
		*(buffer + result) = '\0';
		storage[fd] = ft_save_buffer(buffer, storage[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (result <= 0 && !*(storage + fd))
	{
		*line = ft_strdup("");
		return (result);
	}
	storage[fd] = ft_clean_line(storage[fd], line, result);
	if (result <= 0 && !*(storage + fd))
		return (result);
	return (1);
}