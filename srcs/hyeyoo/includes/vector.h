/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:34:15 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:58:56 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_vector_int
{
	int			x;
	int			y;
}				t_vector_int;

void			init_vector(t_vector *vector, double x, double y);
void			init_vector_int(t_vector_int *vector, int x, int y);
void			rotate(t_vector *vector, double theta);
void			add(t_vector *u, t_vector *v);

#endif
