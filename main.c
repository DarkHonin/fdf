/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/11 15:11:49 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

static  t_point *view = NULL;


int     loop(t_mesh *mesh)
{
	if (view == NULL)
		view = mk_fdf_point(100,100,"0");
	mlx_clear_window(WINDOW->context, WINDOW->window);
	draw_mesh(mesh, view);
	mlx_string_put(WINDOW->context, WINDOW->window, 0,0,0xFFFFFF, print_fdf_point(view));
	return (1);
}

int	key_hook(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		die();
	else if (keycode == KEY_UP)
		view->y -= MESH_SPREAD;
	else if (keycode == KEY_DOWN)
		view->y += MESH_SPREAD;
	view->x = (view->x - ((keycode == KEY_RIGHT) * MESH_SPREAD)) % 180;
	view->x = ABS(view->x + ((keycode == KEY_LEFT) * MESH_SPREAD)) % 360;

	printf("%i\n",keycode);
	return (1);
}

int main(int argc, char **argv)
{
	char *filename;
	int   fd;
	t_mesh  *data;
	t_point *hold;

	if (argc < 2)
		return (-1);
	filename = argv[argc - 1];
	printf("Filename: %s\n", filename);
	fd = open(filename, O_RDONLY);
	data = read_fdf(fd);
	mlx_key_hook(WINDOW->window, &key_hook, NULL);
	mlx_loop_hook(WINDOW->context, &loop, data);
	mlx_loop(WINDOW->context);
	return (0);
}