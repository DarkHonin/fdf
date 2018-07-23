/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:53:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 16:38:27 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3	*mod_ndraw(t_point3 *pnt, t_mesh *mesh)
{
	t_point3 *e;

	e = clone_point(pnt);
	draw_point(e);
	return (e);
}

static void connect_lines(t_point3 *c, t_point3 *p, t_point3 **row, t_point3 **col)
{
	t_point3	*pnt;
	t_point3	*bk;
	t_point3	*tp;

	pnt = point3_dif(c, p);
	if (X(c) > 0)
	{
		bk = point3_dif(row[((int) X(c)) - 1], p);
		draw_line(pnt, bk);
		free(bk);
	}
	if (Y(c) > 0)
	{
		tp = point3_dif(col[((int) X(c))], p);
		draw_line(pnt, tp);
		free(tp);
	}
	draw_point(pnt);
	free(pnt);
}

void	draw_row(t_vector *l, t_vector *ll, t_mesh *d)
{
	t_point3	**list;
	t_point3	**llist;
	int			x;
	t_point3	*pnt;
	t_point3	*cnt;

	list = l->data;
	llist = l->data;
	x = 0;
	while (x < vect_len(l))
	{
		//pnt = point3_dif(list[x], d->center);
		//draw_point(pnt);
		connect_lines(list[x], d->center, list, llist);
		x++;
	}
}
