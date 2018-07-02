/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:15:40 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/02 11:00:02 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define MESH_SPREAD 10
# define KEY_PLUS 69
# define KEY_MINUS 78
# define DEG_RAD(x) ((x * M_PI) / 180)
# define POV (t_point){300, 300, 0}
# define LINE_RESOLUTION 1

# define WINDOW __window()

#include <math.h>
#include "libft.h"
#include <stdio.h>
#include "get_next_line.h"
#include "mlx.h"


typedef struct 	s_point3
{
	double x;
	double y;
	double z;
}				t_point;

typedef t_point ***t_mesh;

typedef struct	s_fdf_window
{
	void	*context;
	void	*window;
}	t_window;


t_window	*__window();
t_window	*open_window(int w, int h, char *title);
t_point 	*new_point(double x, double y, double z);
t_mesh		*new_mesh();
t_mesh  	*add_point(t_mesh *m, t_point *p);
t_point		*get_point(t_mesh *m, unsigned int index);
t_point		*get_next_point(t_mesh *m);
void		draw_point(t_point *a);
void		draw_line(t_point *a, t_point *b);
void		draw_rect(t_point *a, t_point *b, t_point *c, t_point *d);
void		die();
void		print_point(t_point *a);
char	*point_to_str(t_point *a);
t_point		*pov_mod(t_point *a, t_point *b);
t_point		*pos_mod(t_point *a, t_point *b);
t_mesh		*read_fdf(int fd);
#endif