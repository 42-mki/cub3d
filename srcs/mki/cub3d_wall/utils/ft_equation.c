/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 01:35:04 by mki               #+#    #+#             */
/*   Updated: 2021/02/01 21:14:09 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** [ u.x  v.x]
** [ u.y  v.y]

** 1  [ v.y -v.x][a.x]
** det[-u.y  u.x][a.y]
*/

t_vec_d	ft_equation(t_vec_d u, t_vec_d v, t_vec_d a)
{
	t_vec_d	ret;
	double	det;	

	det = u.x * v.y - u.y * v.y;
	ret.x = (v.y * a.x - v.x * a.y) / det;
	ret.y = (u.x * a.y - u.y * a.x) / det;
	
	return (ret);
}

/*
** [ cos -sin][u.x]
** [ sin  cos][u.y]
*/

t_vec_d	ft_rotate_vec(t_vec_d u, t_tri tri, int arrow)
{
	t_vec_d	ret;
	double	sin_val;
	double	cos_val;

	sin_val = arrow ? tri.sin_p : tri.sin_m;
	cos_val = arrow ? tri.cos_p : tri.cos_m;
	ret.x = cos_val * u.x - sin_val * u.y;
	ret.y = sin_val * u.x + cos_val * u.y;
	return (ret);
}
