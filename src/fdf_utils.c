/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 09:55:49 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_point(t_point3 *a)
{
	ft_putchar('{');
	ft_putnbr(X(a));
	ft_putchar(':');
	ft_putnbr(Y(a));
	ft_putchar(':');
	ft_putnbr(Z(a));
	ft_putchar('}');
}

char	*point_to_str(t_point3 *a)
{
	char *ret;

	ret = ft_strnew(0);
	ft_strcat(ret, "{");
	ft_strcat(ret, ft_itoa((int)X(a)));
	ft_strcat(ret, ";");
	ft_strcat(ret, ft_itoa((int)Y(a)));
	ft_strcat(ret, ";");
	ft_strcat(ret, ft_itoa((int)Z(a)));
	ft_strcat(ret, "}");
	return (ret);
}

t_point3	*clone_point(t_point3 *clone)
{
	t_point3 *ret;

	ret = new_matrix(1, 3);
	X(ret) = X(clone);
	Y(ret) = Y(clone);
	Z(ret) = Z(clone);
	return (ret);
}



t_point3_surface to_surface(t_vector *v, int x, int y)
{
	t_point3_surface	ret;
	t_point3_surface	hold;
	t_vector			**lines;
	int					ind;
	
	ft_putstr("Converting to surface...");
	ft_putnbr(vect_len(v));
	ret = MAKE_EMPTY_SURFACE(DIMENTION(x, y));
	lines = v->data;
	ind = 0;
	while (ind < vect_len(v))
	{
		ft_putstr(".");
		ret[ind] = lines[ind]->data;
		ind++;
	}
	ft_putendl("Done");
	return (ret);
}

