/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:48:58 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 11:44:16 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3d_point.h>

t_point3_list		t_list_map(t_point3_list a, size_t len, t_point3 *(*f)(t_point3 *))
{
	int 			x;
	t_point3_list	ret;
	
	ret = MAKE_EMPTY_LIST(len);
	
	x = 0;
	while (x < len)
	{
		ret[x] = f(a[x]);
		x++;
	}
	return (ret);
}

t_point3_surface	t_surface_map(t_point3_surface a, t_dimnetion d, t_point3 *(*f)(t_point3 *))
{
	int 				x;
	int					y;
	t_point3_surface	ret;

	ret = MAKE_EMPTY_SURFACE(d);
	y = 0;
	while (y < d.height)
	{
		x = 0;
		while (x < d.width)
		{
			ret[y][x] = f(a[y][x]);
			x++;
		}
		y++;
	}
	return (ret);
}

void	t_surface_itter(t_point3_surface a, t_dimnetion d, void *(*f)(t_point3 *))
{
	int 				x;
	int					y;

	y = 0;
	while (y < d.height)
	{
		x = 0;
		while (x < d.width)
		{
			f(a[y][x]);
			x++;
		}
		y++;
	}
}

void	t_surface_itter_invert(t_point3_surface a, t_dimnetion d, void *(*f)(t_point3 *))
{
	int 				x;
	int					y;

	y = 0;
	while (y < d.width)
	{
		x = 0;
		while (x < d.height)
		{
			f(a[x][y]);
			x++;
		}
		y++;
	}
}