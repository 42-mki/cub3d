/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:21:48 by mki               #+#    #+#             */
/*   Updated: 2021/01/31 14:52:22 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vec_d	ft_vec_add(t_vec_d a, t_vec_d b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec_d	ft_vec_sub(t_vec_d a, t_vec_d b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

t_vec_d	ft_vec_mul(t_vec_d a, double b)
{
	a.x *= b;
	a.y *= b;
	return (a);
}

t_vec_d	ft_vec_div(t_vec_d a, double b)
{
	a.x /= b;
	a.y /= b;
	return (a);
}
