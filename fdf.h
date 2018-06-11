/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:15:40 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/11 14:53:08 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# define GET_POINT(buff, ret) ft_buffget(sizeof(ret), buff->point_buffer, &ret)
# define GET_POINT_COOR(mesh, x, y, ret) (ft_buffgetn(sizeof(ret), mesh->point_buffer, &ret, x + ((mesh->cols + 1) * y)))
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define MESH_SPREAD 20
# define KEY_PLUS 69
# define KEY_MINUS 78
# define POINT(x) (MESH_SPREAD * x) + 300
# define COLOR(x) (0x0000FF << x)
# define WINDOW __window()

#include "libft.h"
#include <stdio.h>
#include "get_next_line.h"
#include "mlx.h"

typedef struct  s_fdf_data
{
	t_buff *point_buffer;
	int     point_count;
	int		rows;
	int		cols;
	void	*image;
} t_mesh;

typedef struct s_fdf_point
{
	int x;
	int y;
	int z;
} t_point;

typedef struct	s_fdf_window
{
	void	*context;
	void	*window;
}	t_window;

t_mesh		 *read_fdf(int fd);
int			mk_fdf_data(t_mesh **ret);
void		print_fdf(t_mesh *dat);
char		*print_fdf_point(t_point *pnt);
t_point		*mk_fdf_point(int x, int y, char *z);
void		add_point(t_mesh *data, t_point *point);
t_window	*open_window(int w, int h, char *title);
t_window    *__window();
void		die();
void		*create_image(t_mesh *q);
void		draw_mesh(t_mesh *msh, t_point *at);
void		draw_point(t_point *pnt, t_point *mod);

#endif