/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:19:43 by mki               #+#    #+#             */
/*   Updated: 2021/03/09 19:10:52 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H
# define SAVE_H

# define BF_TYPE
# define BF_SIZE
# define BF_RESERVED1
# define BF_RESERVED2
# define BF_OFF_BITS

# define BI_SIZE
# define BI_WIDTH
# define BI_HEIGHT
# define BI_PLANES
# define BI_BIT_COUNT
# define BI_COMPRESSION
# define BI_SIZE_IMAGE
# define BI_X_PELS_PER_METER
# define BI_Y_PELS_PER_METER
# define BI_CLR_USED
# define BI_CLR_IMPORTANT

# define RGBT_BLUE
# define RGBT_GREEN
# define RGBT_RED

typedef struct			s_bitmapfileheader
{
	unsigned short		bf_type;
	unsigned int		bf_size;
	unsigned short		bf_reserved1;
	unsigned short		bf_reserved2;
	unsigned int		bf_off_bits;
}						t_bitmapfileheader;

typedef struct			s_bitmapinfoheader
{
	unsigned int		bi_size;
	int					bi_width;
	int					bi_height;
	unsigned short		bi_planes;
	unsigned short		bi_bit_count;
	unsigned int		bi_compression;
	unsigned int		bi_size_image;
	int					bi_x_pels_per_meter;
	int					bi_y_pels_per_meter;
	unsigned int		bi_clr_used;
	unsigned int		bi_clr_important;
}						t_bitmapinfoheader;

typedef struct			s_bmp
{
	int					save_flag;
	int					fd;
	t_bitmapfileheader	bfh;
	t_bitmapinfoheader	bih;
}						t_bmp;

#endif
