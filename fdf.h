/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:15:40 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/10 16:14:38 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

#include "libft.h"
#include <stdio.h>
#include "get_next_line.h"
#include "mlx.h"

typedef struct  s_fdf_data
{
	t_buff *point_buffer;
	int     point_count;
} t_fdf_data;

typedef struct s_fdf_point
{
	int x;
	int y;
	int z;
} t_fdf_point;

t_fdf_data  *read_fdf(int fd);
int			mk_fdf_data(t_fdf_data **ret);
void		print_fdf(t_fdf_data *dat);
void		print_fdf_point(t_fdf_point *pnt);
t_fdf_point	*mk_fdf_point(int x, int y, char *z);
void		add_point(t_fdf_data *data, t_fdf_point *point);

#endif