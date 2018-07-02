/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:52:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/02 08:59:45 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_window	*__window()
{
	static	t_window *win;

	if(!win)
		win = open_window(1000, 1000, "FdF");
	return (win);
}

void	die()
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