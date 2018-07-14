/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:53:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/14 13:29:31 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*mod_ndraw(t_point *pnt, t_mesh *mesh)
{
	t_point *e;

	e = clone_point(pnt);
	pov_mod(e, mesh);
	pos_mod(e, mesh);
	draw_point(e);
	return (e);
}

void	draw_row(t_vector *l, t_vector *ll, t_mesh *d)
{
	t_point **pnt;
	t_point *hold;
	t_point **odd;
	t_point *dia;

	odd = NULL;
	while ((pnt = vect_get_next(*l)))
	{
		hold = mod_ndraw((*pnt), d);
		if ((*pnt)->x > 0)
		{
			odd = vect_get_shallow(*l, (*pnt)->x - 1);
			dia = mod_ndraw(*odd, d);
			draw_line(hold, dia);
			free(dia);
		}
		if ((*pnt)->y > 0)
		{
			odd = vect_get_shallow(*ll, (*pnt)->x);
			dia = mod_ndraw(*odd, d);
			draw_line(hold, dia);
			free(dia);
		}
		free(hold);
	}
}