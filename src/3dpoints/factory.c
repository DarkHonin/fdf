/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 22:38:28 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/20 22:38:28 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3d_point.h>

t_point3			*make_t_point3(float x, float y, float z)
{
	t_matrix *ret;

	ret = MAKE_EMPTY_POINT;
	X(ret) = x;
	Y(ret) = y;
	Z(ret) = z;
	return (ret);
}

t_point3_list		make_t_point3_list(size_t size)
{
	t_point3_list ret;

	ret = (t_point3_list)ft_memalloc(sizeof(t_point3 *) * size);
	return (ret);
}

t_point3_surface	make_t_point3_surface(size_t w, size_t h)
{
	t_point3_surface	ret;
	int					x;

	ret = (t_point3_surface)ft_memalloc(sizeof(t_point3_list) * h);
	x = 0;
	while (x < h)
		ret[x++] = MAKE_EMPTY_LIST(w);
	return (ret);
}

void				del_point3_list(t_point3_list a, size_t len)
{
	int	x;

	while(x < len)
		FREE_POINT(a[x++]);
	free(*a);
}

void				del_point3_surface(t_point3_surface a, size_t w, size_t h)
{
	int	x;

	while(x < h)
		FREE_LIST(a[x++], w);
	free(*a);
}