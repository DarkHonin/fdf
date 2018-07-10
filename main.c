/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/10 14:55:28 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

static int g_redraw = 1;

t_point			*mod_ndraw(t_point *pnt, t_mesh *mesh)
{
	t_point *e;

	e = clone_point(pnt);
	pov_mod(e, mesh);
	pos_mod(e, mesh);
	draw_point(e);
	return (e);
}

static int		loop(t_mesh *d)
{
	t_point		*pnt;
	t_point		*hold;
	t_vector	l;
	t_vector	ll;

	if (!g_redraw)
		return (1);
	mlx_clear_window(WINDOW->context, WINDOW->window);
	ft_buffreset(d->nodes);
	while ((l = vect_get_next(d->nodes)))
	{
		ft_buffreset(l);
		while ((pnt = vect_get_next(l)))
		{
			hold = mod_ndraw(pnt, d);
			if (pnt->x > 0)
				draw_line(hold, mod_ndraw(vect_get_shallow(l, pnt->x - 1), d));
			if (pnt->y > 0)
				draw_line(hold, mod_ndraw(vect_get_shallow(ll, pnt->x), d));
			free(hold);
		}
		ll = l;
	}
	g_redraw = 0;
	return (1);
}

static int		key_hook(int keycode, t_mesh *mesh)
{
	if (keycode == KEY_ESC)
		die();
	mesh->pov->y = (int)(mesh->pov->y + (keycode == KEY_DOWN) * 5);
	mesh->pov->y = (int)(mesh->pov->y - (keycode == KEY_UP) * 5);
	mesh->pov->x = (int)(mesh->pov->x + ((keycode == KEY_LEFT) * 5));
	mesh->pov->x -= (keycode == KEY_RIGHT) * 5;
	mesh->scale *= (keycode == KEY_PLUS) ? 2 : 1;
	mesh->scale *= (keycode == KEY_MINUS) ? 0.5 : 1;
	g_redraw = 1;
	return (0);
}

int				main(int argc, char **argv)
{
	char	*filename;
	int		fd;
	t_mesh	*data;

	if (argc < 2)
		return (-1);
	filename = argv[argc - 1];
	fd = open(filename, O_RDONLY);
	data = read_fdf(fd);
	mlx_hook(WINDOW->window, 2, 0L, &key_hook, data);
	mlx_loop_hook(WINDOW->context, &loop, data);
	mlx_loop(WINDOW->context);
	return (0);
}
