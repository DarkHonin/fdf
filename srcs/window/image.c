/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:52:23 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 12:10:46 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_window	*get_window()
{
	static t_window	*ret = NULL;

	if (ret)
		return (ret);
	ret = (t_window *)ft_memalloc(sizeof(t_window));
	ret->context = mlx_init();
	if (!ret->context)
		init_error("Could not init mlx");
	ret->window_pointer = mlx_new_window(ret->context, WINDOW_W, WINDOW_H, "FDF");
	if (!ret->window_pointer)
		init_error("Could not create window");
	return (ret);
}

void		close_window()
{
	mlx_destroy_window(get_window()->context,get_window()->window_pointer);
	free(get_window());
}