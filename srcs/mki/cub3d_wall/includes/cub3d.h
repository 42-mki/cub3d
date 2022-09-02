/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:28:31 by mki               #+#    #+#             */
/*   Updated: 2021/02/04 22:35:41 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CUB3D_H
# define	CUB3D_H

# include	"../mlx/mlx.h"
# include	"../libft/libft.h"
/*
**	unistd.h	->	read() close() write()
**	fcntl.h		->	open()
**	limits.h	->	OPEN_MAX
**	stdlib.h	->	malloc(), free(), exit()
**	math.h		->	sin(), cos(), M_PI
**	stdio.h		->	perror() strerror()
*/
# include	<unistd.h>
# include	<fcntl.h>
# include	<limits.h>
# include	<stdlib.h>
# include	<math.h>
# include	<stdio.h>
# include	<sys/errno.h>
/*
**	get_next_line BUFFER_SIZE
*/
# define	BUFFER_SIZE			100
/*
**	X11 Event
*/
# define	X_EVENT_KEY_PRESS	2
# define	X_EVENT_KEY_RELEASE	3
# define	X_EVENT_EXIT		17
/*
**	Apple's key code
*/
# define	KEY_A				0
# define	KEY_S				1
# define	KEY_D				2
# define	KEY_W				13
# define	KEY_ESC				53
# define	ARROW_L				123
# define	ARROW_R				124
/*
**	Color Value
*/
# define 	GREEN				0x00FF00
# define	RED					0xFF0000
# define	WHITE				0xFFFFFF
# define	BLUE				0x0000FF
/*
**	Apple's key code
*/
# define	L_COLOR				RED
# define	W_COLOR				WHITE
/*
**	Apple's key code
*/
# define	PLAYER_COLOR		GREEN
# define	DIR_COLOR			WHITE
# define	PLANE_COLOR			BLUE
# define	P_SIZE				5
# define	MOVE_SPEED			0.001
# define	ROTATE_SPEED		0.005
# define	FOV					90
# define	DIR_LEN				(P_SIZE * 5)
# define	TEX_WIDTH			64
# define	TEX_HEIGHT			64

# define	LEFT				1
# define	RIGHT				0	

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
	int				lineHeight;
	int				draw_start;
	int				draw_end;
	int				color;
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
	int				world_map[24][24];
	int				row;
	int				col;
}					t_cub;

typedef	struct		s_data
{
	t_mlx			mlx;
	t_image			screen;
	t_tri			tri;
	t_line			line;
	t_dda			dda;
	t_cub			cub;
	int				key_flag[256];
	int				wall_flag[4];
	int				texture[4][TEX_HEIGHT * TEX_WIDTH];
	t_image			wall[4];
}					t_data;
/*
**	srcs
*/
int		cub3d(t_data *data);
int		cub_check(t_data *data);
void	key(t_data *d);
int		raycasting(t_data *d);
void	ver_line(t_data *d, int x, int color);
void	pixel_put(t_data *d, int x, int y, int color);
void	load_texture(t_data *d);
/*
**	utils
*/
t_vec_d	ft_vec_add(t_vec_d a, t_vec_d b);
t_vec_d	ft_vec_sub(t_vec_d a, t_vec_d b);
t_vec_d	ft_vec_mul(t_vec_d a, double b);
t_vec_d	ft_vec_div(t_vec_d a, double b);
t_vec_d	ft_equation(t_vec_d u, t_vec_d v, t_vec_d a);
t_vec_d	ft_rotate_vec(t_vec_d u, t_tri tri, int arrow);
int		get_next_line(int fd, char **line);

#endif
