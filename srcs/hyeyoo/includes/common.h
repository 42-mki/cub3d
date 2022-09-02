/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:57:00 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 17:54:01 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "info.h"
# include "sprite.h"
# define TRUE 1
# define FALSE 0
# define WALL '1'
# define SPRITE '2'

typedef struct		s_var
{
	double			*z_buffer;
	t_vector		ray_dir;
	t_vector		side_dist;
	t_vector		delta_dist;
	t_vector		step;
	t_vector_int	map;
	double			perp_wall_dist;
	double			camera_x;
	int				hit;
	int				side;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				line_height;
	double			tex_pos;
	double			dy;
	int				color;
	double			wall_x;
	int				x;
	int				y;
	double			inv_det;
	int				sprite_screen_x;
	int				sprite_width;
	int				stripe;
	int				sprite_height;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
	int				d;
	t_sprite		*sprites;
	t_vector		transform;
}					t_var;

int					main_loop(t_info *info);
void				set_dist_direction(t_info *info, t_var *v);
void				render_walls(t_info *info, t_var *v);
void				render_sprites(t_info *info, t_var *v);
int					is_valid_line(char *line);
int					is_ewsn(char c);

#endif
