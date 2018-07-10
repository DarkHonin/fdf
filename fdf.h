/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:15:40 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/10 14:50:36 by wgourley         ###   ########.fr       */
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
# define LINE_RESOLUTION 1
# define DEPTH 100
# define INIT_Z 0
# define INIT_X 0
# define INIT_Y 0
# define INIT_SCALE 0.1

# define WINDOW mkwindow()

# include <math.h>
# include <libft.h>
# include <vect_ft.h>
# include <stdio.h>
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>

typedef struct	s_point3
{
	float x;
	float y;
	float z;
}				t_point;

typedef struct	s_mesh
{
	t_vector	nodes;
	t_point		*center;
	t_point		*pov;
	t_point		*dimentions;
	double		scale;
}				t_mesh;

typedef struct	s_fdf_window
{
	void	*context;
	void	*window;
}				t_window;

t_window		*mkwindow();
t_window		*open_window(int w, int h, char *title);
t_point			*new_point(float x, float y, float z);
t_point			*get_next_point(t_mesh *m);
void			draw_point(t_point *a);
void			draw_line(t_point *a, t_point *b);
void			draw_rect(t_point *a, t_point *b, t_point *c, t_point *d);
void			die();
void			print_point(t_point *a);
char			*point_to_str(t_point *a);
t_point			*pov_mod(t_point *a, t_mesh *b);
t_point			*pos_mod(t_point *a, t_mesh *b);
t_mesh			*read_fdf(int fd);
t_point			*clone_point(t_point *e);

#endif
