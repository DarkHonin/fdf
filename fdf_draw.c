/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:05:27 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/14 13:59:51 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	get_color(double z)
{
	int ret;
	int base;

	ret = 0x00FF00FF;
	base = 0x00FFFF00 * ((z) / (DEPTH + 10));
	ret |= base;
	return (ret);
}

void		draw_point(t_point *a)
{
	int		bpp;
	int		ll;
	int		end;
	char	*px;
	int		off;

	if (((int)a->x) >= 1000 || ((int)a->y) >= 1000 ||
	((int)a->x) <= 0 || a->y <= 0)
		return ;
	px = mlx_get_data_addr(IMAGE, &bpp, &ll, &end);
	off = (((int)a->x) * (bpp / 8)) + (((int)a->y) * ll);
	*((int *)(px + off)) = get_color(a->z);
}

void		*get_image(int clear)
{
	static void *img = NULL;

	if (clear)
	{
		if (img != NULL)
			mlx_destroy_image(WINDOW->context, img);
		img = NULL;
	}
	if (img == NULL)
		img = mlx_new_image(WINDOW->context, 1000, 1000);
	return (img);
}

void		draw_line(t_point *a, t_point *b)
{
	t_point *delta;
	double	index;
	double	r;
	t_point *pnt;

	index = 0;
	delta = new_point(a->x - b->x, a->y - b->y, a->z - b->z);
	pnt = new_point(0, 0, 0);
	r = sqrt(pow(delta->x, 2) + pow(delta->y, 2));
	while (index < r)
	{
		pnt->x = (delta->x * (index / r)) + b->x;
		pnt->y = (delta->y * (index / r)) + b->y;
		pnt->z = delta->z * (index / r) + b->z;
		draw_point(pnt);
		index += LINE_RESOLUTION;
	}
	free(pnt);
	free(delta);
}
