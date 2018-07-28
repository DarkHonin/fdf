/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:20:37 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 12:44:46 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <3dft.h>


#ifdef MLX_H

void run()
{
	char	*filename;

	if (ac != 2)
		file_error("Invalid number of arguments");
	filename = av[1];
	mlx_hook(get_window()->window_pointer, 2, 0L, &keys, NULL);
	mlx_loop_hook(get_window()->context, &loop, NULL);
	mlx_loop(get_window()->context);
}

static int loop()
{
	return (1);
}

static int keys(int keycode)
{
	if (keycode == KEY_ESC)
		close_window();
	return (1);
}
#endif
#ifdef SDL_h_

void	draw_point(t_point3 a)
{
	t_projected_point *proj;

	proj = standard_projection(&a);
	put_pixel((X(proj) * WINDOW_Z) + WINDOW_C_W, (Y(proj) * WINDOW_Z) + WINDOW_C_H, 255, 0, 0);
	FREE_POINT(proj);
}

void	draw_line(t_line a)
{
	plot_line(a, 0.05, &draw_point);
}


void run()
{
	SDL_Event	e;
	t_point3_list list = MAKE_EMPTY_LIST(4);
	t_line *lines;
	list[0] = *MAKE_POINT(-50, -50, 1);
	list[1] = *MAKE_POINT(50, -50, 1);
	list[2] = *MAKE_POINT(50, 50, 1);
	list[3] = *MAKE_POINT(-50, 50, 1);
	lines = list_to_lines(list, 4);
	line_itter(lines, 3, &draw_line);
	while (1)
	{
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				close_window();
			else if (e.type == SDL_KEYUP)
			{
				Z(list) += (e.key.keysym.scancode == SDL_SCANCODE_UP ? 0.1:-0.1);
				Z((list + 1)) += (e.key.keysym.scancode == SDL_SCANCODE_UP ? 0.1:-0.1);
				Z((list + 2)) += (e.key.keysym.scancode == SDL_SCANCODE_UP ? 0.1:-0.1);
				Z((list + 3)) += (e.key.keysym.scancode == SDL_SCANCODE_UP ? 0.1:-0.1);
				clean();
				line_itter(lines, 3, &draw_line);
			}
		flip();
	}
	
}

#endif


int main(int ac, char **av)
{
	char		*filename;

	if (ac != 2)
		file_error("Invalid number of arguments");
	filename = av[1];
	ft_putendl(filename);
	run();
	return (1);
}