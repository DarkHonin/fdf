/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:05:27 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/02 10:20:33 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw_point(t_point *a)
{
	int base;
	int color;

	base = (int)(((a->z + 1) / 11) * 0x0000FFFF);
	color = base | 0x00000000;
	mlx_pixel_put(WINDOW->context, WINDOW->window, a->x, a->y, color);
}

void	draw_line(t_point *a, t_point *b)
{
	t_point *delta;
	double	index;
	double	r;
	t_point *pnt;

	index = 0;
	delta = new_point(a->x - b->x, a->y - b->y, a->z - b->z);
	pnt = new_point(0,0,0);
	r = sqrt(pow(delta->x, 2) + pow(delta->y, 2));
	while (index < r)
	{
		pnt->x = (delta->x * (index/r)) + b->x;
		pnt->y = (delta->y * (index/r)) + b->y;
		pnt->z = delta->z * (index/r) + b->z;
		draw_point(pnt);
		index+= LINE_RESOLUTION;
	}
}

void	draw_rect(t_point *a, t_point *b, t_point *c, t_point *d)
{
	draw_line(a, b);
	draw_line(b, c);
	draw_line(c, d);
	draw_line(d, a);
	//draw_line(a, c);
	//draw_line(b, d);
}
