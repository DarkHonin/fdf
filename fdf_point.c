/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:30:06 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/11 14:55:00 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_point *pnt, t_point *mod)
{
	if (!mod)
		mlx_pixel_put(WINDOW->context, WINDOW->window,
				POINT(pnt->x),
				POINT(pnt->y),
				COLOR(pnt->z));
	else
		mlx_pixel_put(WINDOW->context, WINDOW->window,
				POINT((pnt->x - 9) * ((double)(mod->x) / 360)),
				POINT((pnt->y - 5) * ((double)(mod->y) / 360)),
				COLOR(pnt->z));
}