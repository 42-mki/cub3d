/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:28:31 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 15:35:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_mms/mlx.h"
# include "../mlx_opengl/mlx.h"
# include "../libft/libft.h"
# include "macro.h"
# include "save.h"
# include "struct.h"
# include "prototype.h"

/*
**	unistd.h	->	read() close() write()
**	fcntl.h		->	open()
**	limits.h	->	OPEN_MAX
**	stdlib.h	->	malloc(), free(), exit()
**	math.h		->	sin(), cos(), M_PI
**	stdio.h		->	perror() strerror()
**	sys/errno.h	->
*/

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <sys/errno.h>

#endif
