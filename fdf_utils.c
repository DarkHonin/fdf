/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/08 12:24:33 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point(t_point *a)
{
	ft_putchar('{');
	ft_putnbr(a->x);
	ft_putchar(':');
	ft_putnbr(a->y);
	ft_putchar(':');
	ft_putnbr(a->z);
	ft_putchar('}');
}

char	*point_to_str(t_point *a)
{
	char *ret;

	ret = ft_strnew(0);
	ft_strcat(ret, "{");
	ft_strcat(ret, ft_itoa((int)a->x));
	ft_strcat(ret, ";");
	ft_strcat(ret, ft_itoa((int)a->y));
	ft_strcat(ret, ";");
	ft_strcat(ret, ft_itoa((int)a->z));
	ft_strcat(ret, "}");
	return (ret);
}

t_point	*pov_mod(t_point *a, t_mesh *b)
{
	double r;
	double rotx;
	double x;
	double y;

	a->x *= MESH_SPREAD * b->scale;
	a->y *= MESH_SPREAD * b->scale;
	a->x -= b->center->x * MESH_SPREAD;
	
	// on x axis
	r = sqrt(pow(a->y, 2) + pow(a->x, 2));
	if (y != 0)
		rotx = atan(a->x / a->y) + DEG_RAD(b->pov->x);
	else
		rotx = atan(x) + DEG_RAD(b->pov->x);
	a->x = r * cos(rotx);
	a->y = r * sin(rotx);
	
	// on y axis z = x
	r = sqrt(pow(a->y, 2) + pow(a->z, 2));
	rotx = atan(a->y / a->z) + DEG_RAD(b->pov->y);
	a->x += r * cos(rotx);
	a->y += r * sin(rotx);
	return (a);
}

t_point	*pos_mod(t_point *a, t_mesh *b)
{
	t_point	*ret;

	ret = a;
	ret->x += 500;
	ret->y += 500;
	return (ret);
}

t_point	*clone_point(t_point *e)
{
	return (new_point(e->x, e->y, e->z));
}
