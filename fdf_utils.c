/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/13 12:57:15 by wgourley         ###   ########.fr       */
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
	double 			x;
	double 			y;
	double 			z;
	static t_matrix *m2d = NULL;
	t_matrix		*pnt;

	if (m2d == NULL)
		m2d = new_matrix(3, 3);

	m2d->cells[0][0] = cos(DEG_RAD(b->pov->x));
	m2d->cells[0][1] = -sin(DEG_RAD(b->pov->x));

	pnt = new_matrix(1, 3);
	pnt->cells[0][0] = a->x - b->center->x;
	pnt->cells[0][1] = a->y - b->center->y;
	pnt->cells[0][2] = a->z;

	printf("%f\n", *matrix_rc_prod(pnt, m2d, 0, 0));
	exit(1);
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
