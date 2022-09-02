/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:42:32 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:49:46 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

int		gnl_return(char **str, char **line, int fd, int ret);
int		get_new_line(char **str, char **line, int fd, int ret);
int		get_next_line(int fd, char **line);

#endif
