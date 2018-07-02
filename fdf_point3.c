/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 08:24:10 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/25 10:42:38 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *new_point(double x, double y, double z)
{
    t_point *ret;

    ret = (t_point *)ft_memalloc(sizeof(t_point));
    ret->x = x;
    ret->y = y;
    ret->z = z;
    return (ret);
}
