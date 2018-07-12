/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/12 15:14:57 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

static int		loop(t_mesh *d)
{
	t_point		*pnt;
	t_point		*hold;
	t_vector	*l;
	t_vector	*ll;

	if (d->redraw == 0)
		return (1);
	CLEAR_IMAGE;
	mlx_clear_window(WINDOW->context, WINDOW->window);
	ft_buffreset(d->nodes);
	while ((l = vect_get_next(d->nodes)))
	{
		ft_buffreset(*l);
		draw_row(l, ll, d);
		ll = l;
	}
	d->redraw = 0;
	mlx_put_image_to_window(WINDOW->context, WINDOW->window, IMAGE, 0, 0);
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
	mesh->redraw = 1;
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
	close(fd);
	mlx_hook(WINDOW->window, 2, 0L, &key_hook, data);
	mlx_loop_hook(WINDOW->context, &loop, data);
	mlx_loop(WINDOW->context);
	return (0);
}
