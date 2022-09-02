/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:36:37 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/07/04 20:58:48 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

void	init_vector(t_vector *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}

void	init_vector_int(t_vector_int *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

void	rotate(t_vector *vector, double theta)
{
	double		x;
	double		y;

	x = vector->x;
	y = vector->y;
	vector->x = x * cos(theta) - y * sin(theta);
	vector->y = x * sin(theta) + y * cos(theta);
}

void	add(t_vector *u, t_vector *v)
{
	u->x += v->x;
	u->y += v->y;
}
