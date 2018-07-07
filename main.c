/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/07 09:02:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

static t_point *g_pov = NULL;
static t_point *g_pos = NULL;
static int g_redraw = 1;

t_point			*mod_ndraw(t_point *pnt)
{
	t_point *e;

	e = clone_point(pnt);
	pov_mod(e, g_pov);
	pos_mod(e, g_pos);
	draw_point(e);
	return (e);
}

static int		loop(t_mesh data)
{
	t_point *pnt;
	t_point *hold;
	t_vector	l;
	t_vector	ll;

	if (g_redraw)
	{
		mlx_clear_window(WINDOW->context, WINDOW->window);
		ft_buffreset(data);
		while ((l = vect_get_next(data)))
		{
			ft_buffreset(l);
			while ((pnt = vect_get_next(l)))
			{
				hold = mod_ndraw(pnt);
				if (pnt->x > 0)
					draw_line(hold, mod_ndraw(vect_get_shallow(l, pnt->x - 1)));
				if (pnt->y > 0)
					draw_line(hold, mod_ndraw(vect_get_shallow(ll, pnt->x)));
				free(hold);
			}
			ll = l;
		}
	}
	g_redraw = 0;
	return (1);
}

static int		key_hook(int keycode, void *args)
{
	if (keycode == KEY_ESC)
		die();
	g_pov->y = (int)(g_pov->y + (keycode == KEY_DOWN) * 5);
	g_pov->y = (int)(g_pov->y - (keycode == KEY_UP) * 5);
	g_pov->x = (int)(g_pov->x + ((keycode == KEY_LEFT) * 5));
	g_pov->x -= (keycode == KEY_RIGHT) * 5;
	g_pov->z += (keycode == KEY_PLUS) * .1;
	g_pov->z -= (keycode == KEY_MINUS) * .1;
	g_pos->x -= (keycode == KEY_A) * 5;
	g_pos->y -= (keycode == KEY_W) * 5;
	g_pos->y += (keycode == KEY_S) * 5;
	g_pos->x += (keycode == KEY_D) * 5;
	g_redraw = 1;
	return (0);
}

int				main(int argc, char **argv)
{
	char	*filename;
	int		fd;
	t_mesh	data;
	t_vector line;
	t_point	*q;

	if (argc < 2)
		return (-1);
	if (g_pov == NULL || g_pos == NULL)
	{
		g_pov = new_point(15, 45, 0.1);
		g_pos = new_point(500, 500, 0);
	}
	filename = argv[argc - 1];
	fd = open(filename, O_RDONLY);
	data = read_fdf(fd);
	ft_buffreset(data);
	while ((line = vect_get_next(data)))
	{
		ft_buffreset(line);
		printf("%p", line);
		while ((q = vect_get_next(line)))
			printf("%s",point_to_str(q));
	}
	mlx_hook(WINDOW->window, 2, 0L, &key_hook, NULL);
	mlx_loop_hook(WINDOW->context, &loop, data);
	mlx_loop(WINDOW->context);
	return (0);
}
