/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:35:54 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 16:07:02 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "info.h"
# pragma pack(push, 1)

typedef struct	s_bmp
{
	char		bmp[2];
	int			size;
	int			unused;
	int			offset;
	int			dib;
	int			width;
	int			height;
	char		plane[2];
	char		bpp[2];
	int			compression;
	int			raw_bitmap_size;
	int			res_x;
	int			res_y;
	int			n_colors;
	int			important_colors;
}				t_bmp;

int				save(t_info *info);

# pragma pack(pop)
#endif
