/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:05:27 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 16:41:57 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	get_color(float z)
{
	int ret;
	int base;

	ret = 0x00000000;
	base = 0x00FFFFFF * ((z + (z == 0)) / 20);
	ret |= base;
	return (ret);
}

static void	put_pixel(t_point2 *a, float color)
{
	int		bpp;
	int		ll;
	int		end;
	char	*px;
	int		off;

	if (a->x >= 1000 || a->y >= 1000 ||
	(a->x) <= 0 || a->y <= 0)
		return ;
	px = mlx_get_data_addr(IMAGE, &bpp, &ll, &end);
	off = (a->x * (bpp / 8)) + (a->y * ll);
	*((int *)(px + off)) = color;
	free(a);
}

void		draw_point(t_point3 *a)
{
	put_pixel(normilise_point(a), get_color(abs(Z(a))));
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

void		draw_line(t_point3 *a, t_point3 *b)
{
	t_point3 *delta;
	double	index;
	float	r;
	t_point3 *pnt;

	index = 0;
	delta = point3_dif(a, b);
	pnt = new_point(0, 0, 0);
	r = point3_dist(a, b);
	while (index < r)
	{
		X(pnt) = (X(delta) * (index / r)) + X(b);
		Y(pnt) = (Y(delta) * (index / r)) + Y(b);
		Z(pnt) = (Z(delta) * (index / r)) + Z(b);
		draw_point(pnt);
		index += LINE_RESOLUTION;
	}
	free(pnt);
	free(delta);
}
