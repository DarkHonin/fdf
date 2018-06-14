/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/14 14:35:22 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <math.h>

static rect Rext = {{
						-50 , -50, 0
					}, {
						50, -50, 5
					}, {
						50,50, 0
					},{
						-50, 50, 10
					}};

static int     loop(t_mesh *mesh)
{
	mlx_clear_window(WINDOW->context, WINDOW->window);
	t_point *A = pov_mod(Rext[0], POV_ROT);
	t_point *B = pov_mod(Rext[1], POV_ROT);
	t_point *C = pov_mod(Rext[2], POV_ROT);
	t_point *D = pov_mod(Rext[3], POV_ROT);
	draw_rect(*A,*B,*C,*D);
	POV_ROT[0]++;
	//POV_ROT[1]++;
	return (1);
}

static int key_hook(int keycode, void *args)
{
	if (keycode == KEY_ESC)
		die();
	return (0);
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