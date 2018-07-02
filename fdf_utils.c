/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/02 12:54:35 by wgourley         ###   ########.fr       */
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

t_point	*pov_mod(t_point *a, t_point *b)
{		
	double zx;
	double zy;
	double spread;
	double bx;
	double by;

	
	bx = cos(DEG_RAD(b->x));
	by = sin(DEG_RAD(b->y));
	zx = cos(DEG_RAD(b->y)) * (a->z / 10);
	zy = sin(DEG_RAD(b->x)) * (a->z / 10);
	spread = (MESH_SPREAD * b->z);
	a->x = (bx * (a->x * spread)) + (zy * spread) - ((a->y * (b->x)) * cos(DEG_RAD(b->y)));
	a->y = (by * (a->y * spread)) + (zx * spread);
	return (a);
}

t_point	*pos_mod(t_point *a, t_point *b)
{
	t_point *ret;

	ret = a;
	ret->x += (b->x);
	ret->y += (b->y);
	return (ret);
}