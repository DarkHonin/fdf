/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_factory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:10:46 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/11 12:36:44 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mk_fdf_data(t_mesh **ret)
{
	*ret = ft_memalloc(sizeof(t_mesh));
	if (!ret)
		return (0);
	(*ret)->point_buffer = ft_buffnew(0,0);
	(*ret)->point_count = 0;
	(*ret)->cols = 0;
	(*ret)->rows = 0;
	return (1);
}

void		add_point(t_mesh *data, t_point *point)
{
	return(ft_buffpush(data->point_buffer, &point, sizeof(t_point *)));
}

t_point	*mk_fdf_point(int x, int y, char *z)
{
	t_point	*ret;

	ret = ft_memalloc(sizeof(ret));
	ret->x = x;
	ret->y = y;
	ret->z = ft_atoi(z);
	return (ret);
}

t_window	*open_window(int w, int h, char *title)
{
	t_window *ret = ft_memalloc(sizeof(t_window));
	ret->context = mlx_init();
	ret->window = mlx_new_window(ret->context, w, h, title);
	return (ret);
}

void	*create_image(t_mesh *q)
{
	void	*img;

	return (img);
}