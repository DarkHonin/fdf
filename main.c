/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/03 15:13:58 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

static t_point *pov = NULL;
static t_point *pos = NULL;
static int redraw = 1;

t_point *mod_ndraw(t_point *pnt)
{
	t_point *e;

	e = clone_point(pnt);
	pov_mod(e, pov);
	pos_mod(e, pos);
	draw_point(e);
	return (e);
}

void draw_mesh(t_mesh data)
{
	t_point *hold;
	t_point *asside;
	int x;
	int y;

	y = 0;
	while (data[y])
	{
		x = 0;
		while ((hold = data[y][x]))
		{
			hold = mod_ndraw(data[y][x]);
			if (x > 0)
			{
				asside = mod_ndraw(data[y][x - 1]);
				draw_line(hold, asside);
				free(asside);
			}
			if (y > 0)
			{
				asside = mod_ndraw(data[y - 1][x]);
				draw_line(hold, asside);
				free(asside);
			}
			free(hold);
			x++;
		}
		y++;
	}
}

static int     loop(t_mesh data)
{
	if (pov == NULL)
		pov = new_point(15, 45, 0.1);
	if (pos == NULL)
		pos = new_point(500, 500, 0);
	if (redraw)
	{
		mlx_clear_window(WINDOW->context, WINDOW->window);
		draw_mesh(data);
	}
	redraw = 0;
	return (1);
}

static int key_hook(int keycode, void *args)
{
	if (keycode == KEY_ESC)
		die();
	pov->y = (int)(pov->y + (keycode == KEY_DOWN) * 5);
	pov->y = (int)(pov->y - (keycode == KEY_UP) * 5);
	pov->x = (int)(pov->x + ((keycode == KEY_LEFT) * 5));
	pov->x -= (keycode == KEY_RIGHT) * 5;
	pov->z += (keycode == KEY_PLUS) * .1;
	pov->z -= (keycode == KEY_MINUS) * .1;
	redraw = 1;
	return (0);
}

int main(int argc, char **argv)
{
	char *filename;
	int   fd;
	t_mesh	*data;
	t_point *hold;

	if (argc < 2)
		return (-1);
	filename = argv[argc - 1];

	printf("Filename: %s\n", filename);
	fd = open(filename, O_RDONLY);
	data = read_fdf(fd);
	mlx_hook(WINDOW->window, 2, 0L, &key_hook, NULL);
	mlx_loop_hook(WINDOW->context, &loop, data);
	mlx_loop(WINDOW->context);
	return (0);
}