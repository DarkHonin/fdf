/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_factory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 14:10:46 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/10 15:28:51 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mk_fdf_data(t_fdf_data **ret)
{
	*ret = ft_memalloc(sizeof(t_fdf_data));
	if (!ret)
		return (0);
	(*ret)->point_buffer = ft_buffnew(0,0);
	(*ret)->point_count = 0;
	return (1);
}

void		add_point(t_fdf_data *data, t_fdf_point *point)
{
	return(ft_buffpush(data->point_buffer, &point, sizeof(t_fdf_point *)));
}

t_fdf_point	*mk_fdf_point(int x, int y, char *z)
{
	t_fdf_point	*ret;

	ret = ft_memalloc(sizeof(ret));
	ret->x = x;
	ret->y = y;
	ret->z = ft_atoi(z);
	return (ret);
}