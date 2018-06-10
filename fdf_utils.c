/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:26:17 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/10 15:30:21 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_fdf(t_fdf_data *dat)
{
	t_fdf_point *point;
	
	ft_putendl("Dumping fdf object");
	ft_buffreset(dat->point_buffer);
	while (ft_buffget(sizeof(point), dat->point_buffer, &point))
		print_fdf_point(point);
}

void	print_fdf_point(t_fdf_point *pnt)
{
	ft_putchar('{');
	ft_putnbr(pnt->x);
	ft_putchar(':');
	ft_putnbr(pnt->y);
	ft_putchar(':');
	ft_putnbr(pnt->z);
	ft_putendl("}");
}