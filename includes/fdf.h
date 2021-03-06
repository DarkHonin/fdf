/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:52:38 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/26 12:24:26 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_W 800
# define WINDOW_H 600
# define WINDOW_Z 0.1
# define MESH_SPREAD 40
# define DEG_RAD(x) ((x * M_PI) / 180)
# define RAD_DEG(x) ((x * 180) / M_PI)

# include <sdlgf.h>
# include <libft.h>
# include <3dft.h>
//# include <SDL2/SDL.h>
#include <mlx.h>
# include <get_next_line.h>

typedef struct	s_map
{
	t_value_v	points;
	t_size		size;
	t_vect3		rotation;
}				t_map;

t_map	*fdf_read_file(char *file);
void 	render(t_map *map);
void 	roate_space(t_space *s, t_value_v ang);

#endif