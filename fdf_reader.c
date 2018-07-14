/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:50:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/14 13:39:58 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>

static t_mesh	*make_mesh(t_vector *nodes, t_point **dimentions)
{
	t_mesh	*ret;

	ret = (t_mesh *)ft_memalloc(sizeof(t_mesh));
	ret->nodes = *nodes;
	ret->dimentions = *dimentions;
	ret->center = new_point((((*dimentions)->x - 1) / 2),
	(((*dimentions)->y - 1) / 2), (((*dimentions)->z - 1) / 2));
	ret->pov = new_point(INIT_X, INIT_Y, INIT_Z);
	ret->scale = INIT_SCALE;
	ret->redraw = 1;
	ft_putstr("Mesh dimentions: ");
	print_point(*dimentions);
	ft_putendl("");
	ft_putstr("Mesh center: ");
	print_point(ret->center);
	ft_putendl("");
	return (ret);
}

static void app_point(t_point *a, t_vector *ln)
{
	t_point *q;
	q = clone_point(a);
	free(a);
	vect_push(*ln, &q);
}

t_mesh			*read_fdf(int fd)
{
	char		*line;
	char		**parts;
	t_vector	ret;
	t_vector	vline;
	t_point		*index;

	ret = MAKE_VECT(sizeof(t_buff *));
	index = new_point(0, 0, 0);
	while (get_next_line(fd, &line))
	{
		parts = ft_strsplit(line, ' ');
		vline = MAKE_VECT(sizeof(t_point *));
		index->x = 0;
		while (parts[(int)index->x])
		{
			index->z = ft_atoi(parts[(int)index->x]);
			app_point(clone_point(index), &vline);
			free(parts[(int)index->x++]);
		}
		vect_push(ret, &vline);
		index->y++;
		free(parts);
		free(line);
	}
	free(line);
	return (make_mesh(&ret, &index));
}
