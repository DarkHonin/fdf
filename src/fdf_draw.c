/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:05:27 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 13:29:22 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	get_color(float z)
{
	int ret;
	int base;

	ret = 0x00000000;
	base = 0x0000FFFF * ((z + (z == 0)) / 10);
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
	if (*((int *)(px + off)) < color)
		*((int *)(px + off)) = color;

}

void		draw_point(t_point3 *a)
{
	static t_point3 *last = NULL;

	put_pixel(normilise_point(a), get_color(abs(Z(a))));
	if (last != NULL && X(last) < X(a))
		draw_line(normilise_point(last), normilise_point(a), Z(last), Z(a));
	last = a;
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

void		draw_line(t_point2 *a, t_point2 *b, float z1, float z2)
{
	float 		i;
	double 		delta;
	t_point2	hold;
	t_point2	dif;
	float		dz;

	delta = sqrtf(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));

	dif.x = a->x - b->x;
	dif.y = a->y - b->y;
	dz = z1 - z2;
	i = 0;
	while (i < delta)
	{
		hold.x = ((dif.x) * (i / delta)) + b->x;
		hold.y = ((dif.y) * (i / delta)) + b->y;
		put_pixel(&hold, get_color((dz * (i / delta)) + z2));
		i += LINE_RESOLUTION;
	}
	free(b);
	free(a);
}
