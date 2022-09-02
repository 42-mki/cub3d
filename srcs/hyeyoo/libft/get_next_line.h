/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:23:18 by abenani           #+#    #+#             */
/*   Updated: 2020/07/01 18:13:12 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

int				get_next_line(const int fd, char **line);
typedef struct	s_node
{
	char			*s;
	int				fd;
	struct s_node	*next;
	struct s_node	*head;
}				t_node;
#endif
