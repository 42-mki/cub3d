/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:28:31 by mki               #+#    #+#             */
/*   Updated: 2021/01/19 20:38:53 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CUB3D_H
#define		CUB3D_H
# include	"../mlx/mlx.h"
# include	<stdlib.h>
# include	<string.h>
# include	<math.h>
# include	<stdio.h>

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
# define	ARROW_L				123
# define	ARROW_R				124

# define 	GREEN				0x00FF00
# define	RED					0xFF0000
# define	WHITE				0xFFFFFF
# define	BLUE				0x0000FF

# define	SIZE				32		
# define	ROWS				24	
# define	COLS				24	
# define	WIDTH				SIZE * ROWS
# define	HEIGHT				SIZE * COLS	
# define	TITLE				"cub3D"
# define	L_COLOR				RED
# define	W_COLOR				WHITE

# define	PLAYER_COLOR		GREEN
# define	DIR_COLOR			WHITE
# define	PLANE_COLOR			BLUE
# define	P_SIZE				5
# define	MOVE_SPEED			5
# define	ROTATE_SPEED		5
# define	ANGLE				1	
# define	FOV					90
# define	DIR_LEN				(P_SIZE * 5)

# define	LEFT				0
# define	RIGHT				1
# define	UP					2
# define	DOWN				3

typedef struct		s_vec
{
	double			x;
	double			y;
}					t_vec;

typedef struct		s_vec_i
{
	int				x;
	int				y;
}					t_vec_i;


typedef struct		s_line
{
	t_vec			delta;
	t_vec			sign;
	double			m;
}					t_line;

typedef struct		s_pixel
{
	double			distance;
	unsigned int	color;
}					t_pixel;

typedef struct		s_sin
{
	double			sin_val_p;
	double			cos_val_p;
	double			sin_val_m;
	double			cos_val_m;
}					t_sin;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_image
{
	void			*img_ptr;
	unsigned int	*img_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef	struct		s_dda
{
	double			camera_x;
	t_vec_i			map;
	t_vec			side_dist;
	t_vec			delta_dist;
	t_vec_i			step;
	double			perp_wall_dist;
	int				hit;
	int				side;
}					t_dda;

typedef	struct		s_data
{
	t_mlx			mlx;
	t_image			screen;
	t_vec			pos;
	t_vec			dir;
	t_vec			pos_dir;
	t_vec			plane;
	t_sin			pai;
	t_line			line;
	t_dda			dda;
	int				key_flag[256];
	int				wall_flag[4];
	int				map_source[ROWS][COLS];
}					t_data;

int		ft_cub3d(t_data *data);
void	ft_init_data(t_data *data);
int		ft_key_press(int key, t_data *data);
int		ft_key_release(int key, t_data *data);
int		ft_exit_button(void);
void	ft_pixel(t_data *data, t_vec pixel, int color);
void	ft_screen(t_data *data);
void	ft_move(t_data *data);
void	ft_rotate(t_data *data);
void	ft_draw_player(t_data *data);
void	ft_draw_lines(t_data *data);
void	ft_draw_rectangles(t_data *data);
void	ft_draw_dir_vec(t_data *data);
void	ft_draw_plane_vec(t_data *data);
void	ft_draw_ray(t_data *data);
void	ft_line(t_data *data, t_vec start, t_vec end, int len);
t_vec	ft_vec_add(t_vec a, t_vec b);
t_vec	ft_vec_sub(t_vec a, t_vec b);
t_vec	ft_vec_mul(t_vec a, double b);
t_vec	ft_vec_div(t_vec a, double b);
t_vec	ft_equation(t_vec u, t_vec v, t_vec a);
t_vec	ft_rotate_vec(t_vec u, t_sin pai, int arrow);

#endif
