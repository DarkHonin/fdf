/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/12 16:00:59 by wgourley         ###   ########.fr       */
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
	double x;
	double y;
	double z;

	x = a->x - b->center->x;
	y = a->y - b->center->y;
	z = (a->z + ((a->z == 0))) + DEPTH;
	x = x * cos(DEG_RAD(b->pov->x));
	y = y * sin(DEG_RAD(b->pov->x));

	a->x = x * (z);
	a->y = y * (z);
	a->z = z;
	return (a);
}

t_point	*pos_mod(t_point *a, t_mesh *b)
{
	double x;
	double y;
	double z;

	x = 500 + (a->x * (MESH_SPREAD * b->scale));
	y = 500 + (a->y * (MESH_SPREAD * b->scale));
	a->x = x;
	a->y = y;
	return (a);
}

t_point	*clone_point(t_point *e)
{
	return (new_point(e->x, e->y, e->z));
}
