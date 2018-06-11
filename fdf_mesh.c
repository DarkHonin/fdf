/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mesh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 09:20:43 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/11 13:22:54 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_mesh(t_mesh *msh, t_point *at)
{
	int x;
	int y;
	t_point *hold;

	y = 0;
	while (y < msh->rows)
	{
		x = 0;
		while (x < msh->cols)
		{
			GET_POINT_COOR(msh, x, y, hold);
			if (hold)
				draw_point(hold, at);
			x++;
		}
		y++;
	}
}
