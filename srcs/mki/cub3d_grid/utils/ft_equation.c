/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 01:35:04 by mki               #+#    #+#             */
/*   Updated: 2021/01/15 11:21:12 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** [ u.x  v.x]
** [ u.y  v.y]

** 1  [ v.y -v.x][a.x]
** det[-u.y  u.x][a.y]
*/

t_vec	ft_equation(t_vec u, t_vec v, t_vec a)
{
	t_vec	ret;
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

t_vec	ft_rotate_vec(t_vec u, t_sin pai, int arrow)
{
	t_vec	ret;
	double	sin_val;
	double	cos_val;

	sin_val = arrow ? pai.sin_val_p : pai.sin_val_m;
	cos_val = arrow ? pai.cos_val_p : pai.cos_val_m;
	ret.x = cos_val * u.x - sin_val * u.y;
	ret.y = sin_val * u.x + cos_val * u.y;
	return (ret);
}
