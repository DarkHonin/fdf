/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 08:24:10 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/14 13:59:02 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(float x, float y, float z)
{
	t_point *ret;

	ret = (t_point *)ft_memalloc(sizeof(t_point));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}
