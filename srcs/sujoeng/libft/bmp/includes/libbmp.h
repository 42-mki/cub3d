/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:42:59 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:45:05 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBMP_H
# define LIBBMP_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "bmp.h"
# include <stdio.h>

void			fill_headers(t_bmp *bmp, int width, int height);
int				fill_imagedata(t_bmp *bmp, char *img, int width, int height);
int				write_rgb(t_bmp *bmp);
void			write_headers(t_bmp *bmp);
int				export_bmp(char *path, char *img, int width, int height);
t_bmp			*init_bmp(int height);
t_bitmap_data	*new_bitmapdata_node(t_uchar b, t_uchar g,
				t_uchar r);
int				check_header(t_bmp *bmp);
t_uint			bytes_to_number(t_uchar *str, t_uint len);
void			number_to_bytes(t_uint nb, unsigned char *buffer, t_uint len);
void			destroy_bmp(t_bmp *bmp);
void			free2d(unsigned char ***str);

#endif
