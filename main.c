/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/02 12:52:25 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

static t_point *pov = NULL;
static t_point *pos = NULL;
static int redraw = 1;
void draw_mesh(t_mesh *data);
static t_point *clone_point(t_point *e)
{
	return (new_point(e->x, e->y, e->z));
}

static int     loop(t_mesh data)
{
	if (redraw)
		draw_mesh(data);
	redraw = 0;
	return (1);
}

void draw_mesh(t_mesh *data)
{
	t_point *hold;
	t_point *asside;

	int x;
	int y;

	if (pov == NULL)
		pov = new_point(90, 90, 10);
	if (pos == NULL)
		pos = new_point(500, 500, 0);

	mlx_clear_window(WINDOW->context, WINDOW->window);
	y = 0;
	while (data[y])
	{
		x = 0;
		while (hold = data[y][x])
		{
			hold = new_point(hold->x, hold->y, hold->z);
			pov_mod(hold, pov);
			pos_mod(hold, pos);
			draw_point(hold);
			mlx_string_put(WINDOW->context, WINDOW->window, hold->x, hold->y, 0x00FFFFFF ,point_to_str(hold));
			if (x > 0)
			{
				asside = clone_point(data[y][x - 1]);
				pov_mod(asside, pov);
				pos_mod(asside, pos);
				draw_line(hold, asside);
				free(asside);
			}
			if (y > 0)
			{
				asside = clone_point(data[y - 1][x]);
				pov_mod(asside, pov);
				pos_mod(asside, pos);
				draw_line(hold, asside);
				free(asside);
			}
			free(hold);
			x++;
		}
		y++;
	}
	mlx_string_put(WINDOW->context, WINDOW->window, 0, 0, 0x00FF0000 ,point_to_str(pov));
}

static int key_hook(int keycode, void *args)
{
	if (keycode == KEY_ESC)
		die();
	pov->y += (keycode == KEY_DOWN) * 5;
	pov->y -= (keycode == KEY_UP) * 5;
	pov->x += (keycode == KEY_LEFT) * 5;
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
	int r = 0xFF0000;
	int g = 0x00FF00;
	int b = 0x0000FF;
	printf("%x\n", (data[0][0]));
	mlx_key_hook(WINDOW->window, &key_hook, NULL);
	mlx_loop_hook(WINDOW->context, &loop, data);
	mlx_loop(WINDOW->context);
	return (0);
}