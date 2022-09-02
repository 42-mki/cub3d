/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:21:48 by mki               #+#    #+#             */
/*   Updated: 2021/01/05 12:11:53 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vec	ft_vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec	ft_vec_sub(t_vec a, t_vec b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

t_vec	ft_vec_mul(t_vec a, double b)
{
	a.x *= b;
	a.y *= b;
	return (a);
}

t_vec	ft_vec_div(t_vec a, double b)
{
	a.x /= b;
	a.y /= b;
	return (a);
}
