/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 02:06:48 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 02:06:48 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3d_point.h>

float		point3_dot(t_point3 *a, t_point3 *b)
{
	return ((X(a) * X(b)) + (Y(a) * Y(b)) + (Z(a) * Z(b)));
}

t_point3	*point3_sum(t_point3 *a, t_point3 *b)
{
	t_point3 *ret;

	ret = make_t_point3(X(a) + X(b), (Y(a) + Y(b)), (Z(a) + Z(b)));
	return (ret);
}

t_point3	*point3_dif(t_point3 *a, t_point3 *b)
{
	t_point3 *ret;

	ret = make_t_point3(X(a) - X(b), (Y(a) - Y(b)), (Z(a) - Z(b)));
	return (ret);
}

t_point3	*cross(t_point3 *a, t_point3 *b)
{
	t_point3 *ret;

	ret = make_t_point3((Y(a) * Z(b)) - (Z(a) * Y(b)), 
						(Z(a) * X(b)) - (X(a) * Z(b)),
						(X(a) * Y(b)) - (Y(a) * X(b)));
	return (ret);
}