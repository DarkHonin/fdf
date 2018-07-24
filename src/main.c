/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 13:33:17 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

t_mesh	**get_mesh()
{
	static t_mesh *mesh;

	return (&mesh);
}

static void	center(t_point3 *a)
{
	t_mesh	**m;
	t_point3 *hold;
	
	m = get_mesh();
	hold = point3_dif(a, (*m)->center);
	X(a) = X(hold);
	Y(a) = Y(hold);
	Z(a) = Z(hold);
	free(hold);
	ft_putstr(".");
}

static int		loop(t_mesh *d)
{
	t_point3_surface 	q;

	if (d->redraw == 0)
		return (1);
	CLEAR_IMAGE;
	mlx_clear_window(WINDOW->context, WINDOW->window);
	q = d->nodes;
	ft_putendl("Starting image render");
	t_surface_itter(q, DIMENTION(X(d->dimentions), Y(d->dimentions)), &draw_point);
	t_surface_itter_invert(q, DIMENTION(X(d->dimentions), Y(d->dimentions)), &draw_vert_lines);
	ft_putendl("Image render complete");
	d->redraw = 0;
	mlx_put_image_to_window(WINDOW->context, WINDOW->window, IMAGE, 0, 0);
	*get_rotate() = 0;
	return (1);
}

static int		key_hook(int keycode)
{
	t_mesh 				*msh;
	t_point3_surface 	q;

	if (keycode == KEY_ESC)
		die();
	msh = *get_mesh();
	msh->scale -= 0.1 * (keycode == KEY_MINUS);
	msh->scale += 0.1 * (keycode == KEY_PLUS);
	
	msh->redraw = 1;
	return (0);
}

int				main(int argc, char **argv)
{
	char				*filename;
	int					fd;
	t_mesh				**mesh;
	t_point3_surface	hold;

	if (argc < 2)
		return (-1);
	filename = argv[argc - 1];
	fd = open(filename, O_RDONLY);
	mesh = get_mesh();
	*mesh = read_fdf(fd);
	close(fd);
	ft_putstr("Centering...");
	t_surface_itter((*mesh)->nodes, DIMENTION(X((*mesh)->dimentions), Y((*mesh)->dimentions)), &center);
	ft_putendl("Done");
	mlx_hook(WINDOW->window, 2, 0L, &key_hook, NULL);
	mlx_loop_hook(WINDOW->context, &loop, *mesh);
	mlx_loop(WINDOW->context);
	return (0);
}
