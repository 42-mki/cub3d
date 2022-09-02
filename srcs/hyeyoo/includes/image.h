/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:06:27 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/01 18:29:49 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct	s_image
{
	void		*img;
	int			*data;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
}				t_image;

void			clear(t_image *img);

#endif
