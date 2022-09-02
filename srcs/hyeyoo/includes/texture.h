/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:04:23 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/02 22:02:26 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "info.h"
# include "image.h"
# define TEXTURE_WIDTH	64
# define TEXTURE_HEIGHT 64
# define EAST_IDX 0
# define WEST_IDX 1
# define SOUTH_IDX 2
# define NORTH_IDX 3
# define SPRITE_IDX 4

void	load_texture(t_info *info, t_image *img, char *path);
int		get_direction(t_vector ray_dir, int side);

#endif
