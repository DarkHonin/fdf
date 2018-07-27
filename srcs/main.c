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


int main(int ac, char **av)
{
	char	*filename;

	if (ac != 2)
		file_error("Invalid number of arguments");
	filename = av[1];
	mlx_hook(get_window()->window_pointer, 2, 0L, &keys, NULL);
	mlx_loop_hook(get_window()->context, &loop, NULL);
	mlx_loop(get_window()->context);
}