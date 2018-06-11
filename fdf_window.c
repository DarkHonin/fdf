/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 08:52:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/11 14:53:02 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_window	*__window()
{
	static	t_window *win;

	if(!win)
		win = open_window(600, 600, "FdF");
	return (win);
}

void	die()
{
	mlx_destroy_window(WINDOW->context, WINDOW->window);
	free(WINDOW);
	exit(1);
}