/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:15:40 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 13:20:27 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define MESH_SPREAD 10
# define KEY_PLUS 69
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_MINUS 78
# define DEG_RAD(x) ((x * M_PI) / 180)
# define RAD_DEG(x) ((x * 180) / M_PI)
# define LINE_RESOLUTION 0.1
# define INIT_Z 0
# define INIT_X 0
# define INIT_Y 0
# define INIT_SCALE 1
# define X(point) point->cells[0][0]
# define Y(point) point->cells[0][1]
# define Z(point) point->cells[0][2]
# define WINDOW_W 800
# define WINDOW_H 600
# define WINDOW_CENTER_X WINDOW_W/2
# define WINDOW_CENTER_Y WINDOW_H/2
# define WINDOW mkwindow()
# define IMAGE get_image(0)
# define CLEAR_IMAGE get_image(1)

# include <math.h>
# include <libft.h>
# include <vect_ft.h>
# include <stdio.h>
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <matrix_ft.h>
# include <3d_point.h>

typedef struct		s_point2
{
	int	x;
	int y;
}					t_point2;

typedef struct	s_mesh
{
	t_point3_surface	nodes;
	t_point3			*center;
	t_point3			*pov;
	t_point3			*dimentions;
	int					redraw;
	double				scale;
}				t_mesh;

typedef struct	s_fdf_window
{
	void	*context;
	void	*window;
}				t_window;

t_window			*mkwindow();
t_window			*open_window(int w, int h, char *title);
t_point3			*new_point(float x, float y, float z);
t_point3			*get_next_point(t_mesh *m);
void				draw_point(t_point3 *a);
void				draw_line(t_point2 *a, t_point2 *b, float z1, float z2);
void				die();
void				print_point(t_point3 *a);
char				*point_to_str(t_point3 *a);
t_point3			*pov_mod(t_point3 *a, t_mesh *b);
t_point3			*pos_mod(t_point3 *a, t_mesh *b);
t_mesh				*read_fdf(int fd);
t_point3			*clone_point(t_point3 *e);
void				*get_image(int clear);
void				draw_row(t_vector *line, t_vector *last, t_mesh *d);
t_point3			*point3_dif(t_point3 *a, t_point3 *b);
t_point2			*normilise_point(t_point3 *a);
float				point3_dist(t_point3 *a, t_point3 *b);
t_point3_surface	to_surface(t_vector *v, int x, int y);
t_mesh				**get_mesh();
void				draw_vert_lines(t_point3 *a);
float				*get_rotate();
#endif
