/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:53:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/12 14:04:38 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*mod_ndraw(t_point *pnt, t_mesh *mesh)
{
	t_point *e;

	e = clone_point(pnt);
	pov_mod(e, mesh);
	pos_mod(e, mesh);
	draw_point(e);
	return (e);
}

void    draw_row(t_vector *l, t_vector *ll, t_mesh *d)
{
    t_point *pnt;
    t_point *hold;
    t_point *odd;

    odd = NULL;
    while ((pnt = vect_get_next(*l)))
    {
        hold = mod_ndraw(pnt, d);
        if (pnt->x > 0)
        {
            odd = mod_ndraw(vect_get_shallow(*l, pnt->x - 1), d);
            draw_line(hold, odd);
            free(odd);
        }
        if (pnt->y > 0)
        {
            odd = mod_ndraw(vect_get_shallow(*ll, pnt->x), d);
            draw_line(hold, odd);
            free(odd);
        }
        free(hold);
    }
}