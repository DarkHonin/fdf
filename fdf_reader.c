/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:50:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/08 10:55:11 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>

static void itter_node_vertex(t_vector a, t_point *b)
{
	print_point(b);
	ft_putendl("");
}

static void itter_node_lines(t_vector a, t_vector b)
{
	ft_putendl("------------");
	ft_putstr(ft_itoa_b(((int)b >> 4) & 0xffffffff, 16));
	ft_putendl("\n----------------");
	vect_itter(b, &itter_node_vertex);
}


static t_mesh	*make_mesh(t_vector *nodes, t_point **dimentions)
{
	t_mesh	*ret;

	ret = (t_mesh *)ft_memalloc(sizeof(t_mesh));
	ret->nodes = *nodes;
	ret->dimentions = *dimentions;
	ret->center = new_point(((*dimentions)->x/2),((*dimentions)->y/2), ((*dimentions)->z/2));
	ret->pov = new_point(45,45,0);
	ret->scale = 1;
	ft_putstr("Mesh dimentions: ");
	print_point(*dimentions);
	ft_putendl("");
	ft_putstr("Mesh center: ");
	print_point(ret->center);
	ft_putendl("");
	vect_itter(*nodes, &itter_node_lines);
	return (ret);
}

t_mesh 			*read_fdf(int fd)
{
	char *line;
	char **parts;
	t_vector ret;
	t_vector vline;
	t_point *index;

	ret = MAKE_VECT(sizeof(t_buff));
	index = new_point(0,0,0);
	ft_putendl("Reading file");
	while (get_next_line(fd, &line))
	{
		ft_putstr(">> ");
		ft_putendl(line);
		parts = ft_strsplit(line, ' ');
		vline = MAKE_VECT(sizeof(t_point));
		index->x = 0;
		while (parts[(int)index->x])
		{
			index->z = ft_maxi(ft_atoi(parts[(int)index->x]), index->z);
			vect_push(vline, new_point(index->x, index->y, ft_atoi(parts[(int)index->x])));
			index->x++;
		}
		vect_push(ret, vline);
		index->y++;
	}
	return (make_mesh(&ret, &index));
}
