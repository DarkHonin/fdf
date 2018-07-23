/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:50:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 16:43:32 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include "get_next_line.h"
#include <fcntl.h>

static void		check(t_vector *line, t_point3 *dif)
{
	if (vect_len(line) != X(dif))
	{
		ft_putendl("Invalid file, row length invalid");
		exit(0);
	}
}


static t_mesh	*make_mesh(t_vector *nodes, t_point3 **dimentions)
{
	t_mesh		*ret;
	int			x;
	t_vector	**lst;

	x = 0;
	ret = (t_mesh *)ft_memalloc(sizeof(t_mesh));
	ret->nodes = nodes;
	ret->dimentions = *dimentions;
	ret->center = new_point(((X(ret->dimentions) - 1) / 2),
	((Y(ret->dimentions) - 1) / 2), Z(ret->dimentions));
	ret->pov = new_point(INIT_X, INIT_Y, INIT_Z);
	ret->scale = INIT_SCALE;
	ret->redraw = 1;
	ft_putstr("Mesh dimentions: ");
	ft_putendl(point_to_str(*dimentions));
	ft_putstr("Mesh center: ");
	print_point(ret->center);
	ft_putendl(point_to_str(ret->center));
	ft_putstr("Validating...");
	lst = vect_to_list(nodes);
	while (x < vect_len(nodes))
		check(lst[x++], *dimentions);
	ft_putendl("OK");
	return (ret);
}

static void		app_point(t_point3 *a, t_vector *ln)
{
	t_point3 *q;

	q = clone_point(a);
	vect_push(ln, &q);
}

t_mesh			*read_fdf(int fd)
{
	char		*line;
	char		**parts;
	t_vector	*ret;
	t_vector	*vline;
	t_point3	*index;

	ret = MAKE_VECT(sizeof(t_vector *));
	index = new_point(0, 0, 0);
	while (get_next_line(fd, &line))
	{
		parts = ft_strsplit(line, ' ');
		vline = MAKE_VECT(sizeof(t_point3 *));
		X(index) = 0;
		while (parts[(int)X(index)])
		{
			Z(index) = ft_atoi(parts[(int)X(index)]);
			app_point(index, vline);
			free(parts[(int)X(index)++]);
		}
		vect_push(ret, &vline);
		Y(index)++;
		free(parts);
		free(line);
	}
	return (make_mesh(ret, &index));
}
