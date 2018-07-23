/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:13:32 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 16:10:34 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

t_point2	*normilise_point(t_point3 *a)
{
	t_point2 *ret;

	ret = (t_point2 *)ft_memalloc(sizeof(t_point2));
	ret->x = a->cells[0][0] / ((Z(a) + (Z(a) == 0)) / 510);
	ret->y = a->cells[0][1] / ((Z(a) + (Z(a) == 0)) / 510);
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
