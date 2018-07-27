/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:52:23 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 12:45:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.sdl.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

t_window	*get_window()
{
	static t_window	*ret = NULL;

	if (ret)
		return (ret);
	ret = (t_window *)ft_memalloc(sizeof(t_window));
	ret->context = SDL_Init(SDL_INIT_VIDEO);
	if (!ret->context)
		init_error("Could not init libriary");
	ret->window_pointer = SDL_CreateWindow("FDF", 0, 0, WINDOW_W, WINDOW_H);
	if (!ret->window_pointer)
		init_error("Could not create window");
	return (ret);
}

void		close_window()
{
	SDL_DestroyWindow(get_window()->window_pointer);
	free(get_window());
	exit(1);
}