/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 09:03:24 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 13:03:45 by wgourley         ###   ########.fr       */
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