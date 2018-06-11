/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:26:17 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/11 14:24:56 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_fdf(t_mesh *dat)
{
	t_point *point;
	
	ft_putendl("Dumping fdf object");
	ft_buffreset(dat->point_buffer);
	while (GET_POINT(dat, point))
	{
		if (point->x == 0)
			ft_putendl("");
		ft_putstr(print_fdf_point(point));
	}
}

char	*print_fdf_point(t_point *pnt)
{
	char *q;
	q = ft_strnew(0);
	ft_strcat(q, "{");
	ft_strcat(q, ft_itoa(pnt->x));
	ft_strcat(q, ":");
	ft_strcat(q, ft_itoa(pnt->y));
	ft_strcat(q, ":");
	ft_strcat(q, ft_itoa(pnt->z));
	ft_strcat(q, "}");
	return (q);
}