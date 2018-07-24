/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:53:14 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 12:07:46 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _3D_THINGS_H
# define _3D_THINGS_H

# include <matrix_ft.h>

# define X(point) point->cells[0][0]
# define Y(point) point->cells[0][1]
# define Z(point) point->cells[0][2]

typedef t_matrix 	t_point3;
typedef	t_point3 	**t_point3_list;
typedef t_point3	***t_point3_surface;

typedef struct		s_dimention
{
	int	width;
	int height;
}					t_dimnetion;

# define MAKE_EMPTY_POINT 			(t_point3 *)new_matrix(1, 3)
# define MAKE_EMPTY_LIST(size)		make_t_point3_list(size)
# define MAKE_EMPTY_SURFACE(d)		make_t_point3_surface(d.width, d.height)
# define MAKE_POINT(x, y, z) 		make_t_point3(x, y, z)
# define FREE_POINT(pnt)			del_matrix(pnt)
# define FREE_LIST(lst, len)		del_point3_list(lst, len)
# define DIMENTION(x, y)			(t_dimnetion) {x, y}

t_point3			*make_t_point3(float x, float y, float z);
t_point3_list		make_t_point3_list(size_t size);
t_point3_surface	make_t_point3_surface(size_t w, size_t h);
t_point3_list		t_list_map(t_point3_list a, size_t len, t_point3 *(*f)(t_point3 *));
t_point3_surface	t_surface_map(t_point3_surface a, t_dimnetion d, t_point3 *(*f)(t_point3 *));
void				del_point3_list(t_point3_list a, size_t len);
void				del_point3_surface(t_point3_surface a, size_t w, size_t h);
void				t_surface_itter(t_point3_surface a, t_dimnetion d, void *(*f)(t_point3 *));
void				t_surface_itter_invert(t_point3_surface a, t_dimnetion d, void *(*f)(t_point3 *));
t_matrix 			*get_rot_matrix_y(float deg);
t_matrix 			*get_rot_matrix_x(float deg);
t_matrix 			*get_rot_matrix_z(float deg);

float				point3_dot(t_point3 *a, t_point3 *b);
t_point3			*point3_sum(t_point3 *a, t_point3 *b);
t_point3			*point3_dif(t_point3 *a, t_point3 *b);
t_point3			*cross(t_point3 *a, t_point3 *b);

#endif