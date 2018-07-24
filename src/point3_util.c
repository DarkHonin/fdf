/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:13:32 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 13:32:00 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

t_point2	*normilise_point(t_point3 *a)
{
	t_point2 	*ret;
	float		z;
	float		max;

	ret = (t_point2 *)ft_memalloc(sizeof(t_point2));
	max = Z((*get_mesh())->dimentions);
	z = ft_mini(Z(a) + (Z(a) == 0), max/10);
	ret->x = a->cells[0][0] * (z / max) * 255;
	ret->y = a->cells[0][1] * (z / max) * 255;
	ret->x *= (*get_mesh())->scale;
	ret->y *= (*get_mesh())->scale;
	ret->x += WINDOW_CENTER_X;
	ret->y += WINDOW_CENTER_Y;
	return (ret);
}

float		dst_from_center(t_point3 *e)
{
	return (sqrtf(powf(X(e), 2) + powf(Y(e), 2) + powf(Z(e), 2)));
}

float		point3_dist(t_point3 *a, t_point3 *b)
{
	return (abs(sqrtf(powf(X(a) - X(b), 2) + powf(Y(a) - Y(b), 2) + powf(Z(a) - Z(b), 2))));
}

void		draw_vert_lines(t_point3 *a)
{
	static t_point3 *last = NULL;

	if (last != NULL && Y(last) < Y(a))
		draw_line(normilise_point(last), normilise_point(a), Z(last), Z(a));
	last = a;
}

float		*get_rotate()
{
	static float *rot = NULL;
	
	if (!rot)
		rot = ft_memalloc(sizeof(float));
	return (rot);
}