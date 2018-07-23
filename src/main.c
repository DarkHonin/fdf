/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 15:57:17 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

static int		loop(t_mesh *d)
{
	t_vector	**lines;
	int			max;
	int			x;

	if (d->redraw == 0)
		return (1);
	CLEAR_IMAGE;
	mlx_clear_window(WINDOW->context, WINDOW->window);
	lines = d->nodes->data;
	max = vect_len(d->nodes);

	x = 0;
	ft_putendl("Starting image render");
	ft_putstr("Mesh height: ");
	ft_putnbr(max);
	ft_putendl("");
	while (x < max)
	{
		draw_row(lines[x], lines[ft_maxi(x - 1, x)], d);
		x++;
	}
	ft_putendl("Image render complete");
	d->redraw = 0;
	mlx_put_image_to_window(WINDOW->context, WINDOW->window, IMAGE, 0, 0);
	return (1);
}

static int		key_hook(int keycode, t_mesh *mesh)
{
	if (keycode == KEY_ESC)
		die();
	X(mesh->center) -= (keycode == KEY_RIGHT);
	X(mesh->center) += (keycode == KEY_LEFT);
	Y(mesh->center) += (keycode == KEY_UP);
	Y(mesh->center) -= (keycode == KEY_DOWN);
	Z(mesh->center) += (keycode == KEY_PLUS);
	Z(mesh->center) -= (keycode == KEY_MINUS);
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
