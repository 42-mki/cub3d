/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:22:32 by mki               #+#    #+#             */
/*   Updated: 2021/03/11 17:45:47 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_vec_d
{
	double			x;
	double			y;
}					t_vec_d;

typedef struct		s_vec_i
{
	int				x;
	int				y;
}					t_vec_i;

typedef struct		s_line
{
	t_vec_d			delta;
	t_vec_d			sign;
	double			m;
}					t_line;

typedef struct		s_pixel
{
	double			distance;
	unsigned int	color;
}					t_pixel;

typedef struct		s_tri
{
	double			sin_p;
	double			sin_m;
	double			cos_p;
	double			cos_m;
}					t_tri;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_image
{
	void			*img_ptr;
	int				*img_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef	struct		s_dda
{
	t_vec_d			pos;
	t_vec_d			dir;
	t_vec_d			plane;
	double			camera_x;
	t_vec_d			ray;
	t_vec_i			map;
	t_vec_d			side_dist;
	t_vec_d			delta_dist;
	double			perp_wall_dist;
	t_vec_i			step;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			*buffer;
}					t_dda;

typedef	struct		s_cub
{
	int				width;
	int				height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f;
	int				c;
	int				**world_map;
	int				row;
	int				col;
	int				floor;
	int				ceiling;
	char			dir;
	int				dir_cnt;
}					t_cub;

typedef struct		s_tex
{
	char			*path[5];
	double			wall_x;
	int				x;
	int				y;
	double			step;
	double			pos;
	int				color;
}					t_tex;

typedef struct		s_spr
{
	int				num_sprite;
	int				*sprite_order;
	double			*sprite_dist;
	t_vec_d			sprite;
	double			det;
	t_vec_d			tf;
	int				screen_x;
	int				v_move_screen;
	int				width;
	int				height;
	t_vec_i			draw_start;
	t_vec_i			draw_end;
	int				stripe;
	t_vec_i			tex;
	int				i;
	int				y;
	int				d;
	int				color;
	t_vec_d			*pos;
}					t_spr;

typedef struct		s_par
{
	char			*file;
	int				fd;
	char			*get_line;
	t_list			*lst_begin;
	t_list			*lst;
	t_list			*map_begin;
	int				map_start_idx;
	int				info_cnt;
	int				line_cnt;
	int				check[8];
}					t_par;

typedef	struct		s_data
{
	t_mlx			mlx;
	t_image			screen;
	t_tri			tri;
	t_line			line;
	t_dda			dda;
	t_cub			cub;
	t_bmp			bmp;
	int				key_flag[256];
	int				wall_flag[4];
	int				texture[5][TEX_HEIGHT * TEX_WIDTH];
	t_tex			tex;
	t_spr			spr;
	t_par			par;
}					t_data;

#endif
