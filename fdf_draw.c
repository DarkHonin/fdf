/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:05:27 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/14 14:36:00 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw_point(t_point a)
{
	int base;
	int color;

	base = (int)((a[2] / 10) * 255);
	color = base | 0xFF000F;
	mlx_pixel_put(WINDOW->context, WINDOW->window, a[0] + POV[0], a[1] + POV[1], color);
}

void	draw_line(t_point a, t_point b)
{
	t_point delta;
	double	index;
	double	r;
	t_point pnt;

	index = 0;
	delta[0] = (a[0] - b[0]);
	delta[1] = (a[1] - b[1]);
	delta[2] = (a[2] - b[2]);
	
	r = sqrt(pow(delta[0], 2) + pow(delta[1], 2));
	while (index < r)
	{
		pnt[0] = (delta[0] * (index/r)) + b[0];
		pnt[1] = (delta[1] * (index/r)) + b[1];
		pnt[2] = delta[2] * (index/r) + b[2];
		draw_point(pnt);
		index+= 1;
	}
}

void	draw_rect(t_point a, t_point b, t_point c, t_point d)
{
	draw_line(a, b);
	draw_line(b, c);
	draw_line(c, d);
	draw_line(d, a);
	//draw_line(a, c);
	//draw_line(b, d);
}