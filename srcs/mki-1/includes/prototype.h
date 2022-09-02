/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:21:32 by mki               #+#    #+#             */
/*   Updated: 2021/03/10 17:56:32 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define PROTOTYPE_H

/*
**	srcs
*/

int					cub3d(t_data *data);

/*
**	ft_vector.c
*/

int					parsing(t_data *data);
int					parsing_info(t_data *d, t_list *lst_begin);
int					parsing_res(t_data *d, char **s);
int					parsing_tex(char **d, char **s);
int					parsing_fc(char **s, int *value);
int					parsing_map(t_data *d);
int					map_is_valid(t_cub *cub, int **map);

/*
**	ft_vector.c
*/

void				init_vec(t_data *d);
int					player_direction(t_dda *dda, char c);
void				key(t_data *d);
int					raycasting(t_data *d);
void				ver_line(t_data *d, int x, int color);
void				pixel_put(t_data *d, int x, int y, int color);
int					load_texture(t_data *d);
void				wall(t_data *d);

/*
**	ft_vector.c
*/

void				calc_textures(t_data *d, t_tex *tex);
void				put_textures(t_data *d, t_tex *tex, int x);

/*
**	ft_vector.c
*/

void				sprites(t_data *d, t_spr *s);
void				calc_sprites(t_data *d, t_spr *s);
void				count_sprites(t_data *d, t_spr *s);
void				sprites_locate(t_data *d, t_spr *s);
int					sprites_malloc(t_spr *s);
void				sprites_free(t_spr *s);
void				floor_ceiling(t_data *d);

/*
**	bmp.c
*/

void				bmp(t_data *d, int *img_data, t_bmp *b);

/*
**	ft_vector.c
*/

t_vec_d				ft_vec_add(t_vec_d a, t_vec_d b);
t_vec_d				ft_vec_sub(t_vec_d a, t_vec_d b);
t_vec_d				ft_vec_mul(t_vec_d a, double b);
t_vec_d				ft_vec_div(t_vec_d a, double b);

/*
**	ft_equation.c
*/

t_vec_d				ft_equation(t_vec_d u, t_vec_d v, t_vec_d a);
t_vec_d				ft_rotate_vec(t_vec_d u, t_tri tri, int arrow);

/*
**	get_next_line.c
*/

int					get_next_line(int fd, char **line);

#endif
