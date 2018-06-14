/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/14 14:51:21 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	print_point(t_point a)
{
	ft_putchar('{');
	ft_putnbr(a[0]);
	ft_putchar(':');
	ft_putnbr(a[1]);
	ft_putchar(':');
	ft_putnbr(a[2]);
	ft_putchar('}');
}

t_point	*pov_mod(t_point a, t_point b)
{
	t_point *ret;
	ret = (t_point *)ft_memalloc(sizeof(t_point));
	(*ret)[0] = (cos(DEG_RAD(b[0])) * a[0]) - (sin(DEG_RAD(b[0])) * ((a[2] / 10) * 50));
	(*ret)[1] = (sin(DEG_RAD(b[1])) * a[1]) - (cos(DEG_RAD(b[1])) * ((a[2] / 10) * 50));
	(*ret)[2] = a[2];
	return (ret);
}