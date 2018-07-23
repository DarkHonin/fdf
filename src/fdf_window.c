/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:52:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 13:15:13 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_window	*mkwindow(void)
{
	static	t_window *win;

	if (!win)
		win = open_window(WINDOW_W, WINDOW_H, "FdF");
	return (win);
}

void		die(void)
{
	mlx_destroy_window(WINDOW->context, WINDOW->window);
	free(WINDOW);
	exit(1);
}

t_window	*open_window(int w, int h, char *title)
{
	t_window *window;

	window = (t_window *)ft_memalloc(sizeof(t_window));
	window->context = mlx_init();
	window->window = mlx_new_window(window->context, w, h, title);
	return (window);
}
