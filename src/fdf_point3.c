/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_point3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 08:24:10 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 12:37:09 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3	*new_point(float x, float y, float z)
{
	t_point3 *ret;

	ret = new_matrix(1, 3);
	X(ret) = x;
	Y(ret) = y;
	Z(ret) = z;
	return (ret);
}
