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

void run()
{
	SDL_Event	e;
	SDL_Renderer *a = SDL_CreateRenderer(get_window()->window_pointer, 0, SDL_RENDERER_SOFTWARE);
	while (1)
	{
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT)
				close_window();
		SDL_RenderPresent(a);
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