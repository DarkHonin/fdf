/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/07 14:44:44 by wgourley         ###   ########.fr       */
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
	double roty;

	a->x *= MESH_SPREAD * b->scale;
	a->y *= MESH_SPREAD * b->scale;
	r = sqrt(pow(a->y, 2) + pow(a->x, 2));
	rotx = 0;
	if (a->y != 0)
		rotx = atan(a->x / a->y) + DEG_RAD(b->pov->x);
	else
		rotx = atan(a->x) + DEG_RAD(b->pov->x);
	a->x = r * cos(rotx);
	a->y = r * sin(rotx);

	roty = atan(a->x / a->z) + DEG_RAD(b->pov->y);
	r = sqrt(pow(a->z, 2) + pow(a->x, 2));
	a->x = r * cos(roty);
	a->y = r * sin(roty);
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
