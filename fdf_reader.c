/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:50:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/03 15:18:19 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>


t_mesh	*localize(t_mesh a, double lx, double ly)
{
	int max_x;
	int max_y;
	int x;
	int y;
	
	y = 0;
	max_y = 0;
	while (y < ly)
	{
		if (a[y] == NULL)
			return (NULL);
		x = 0;
		while (x < lx)
		{
			if (a[y][x] == NULL)
				return (NULL);
			((t_point *)a[y][x])->x -= (lx/2);
			((t_point *)a[y][x])->y -= (ly/2);
			x++;
		}
		y++;
	}
	
}

t_mesh	*read_fdf(int fd)
{
	char *line;
	char **parts;
	t_mesh *ret;
	t_point *index;

	ret = (t_mesh *)ft_memalloc(sizeof(t_point ***));
	index = new_point(0,0,0);
	ft_putendl("Reading file");
	while (get_next_line(fd, &line))
	{
		ft_putstr(">> ");
		ft_putendl(line);
		parts = ft_strsplit(line, ' ');
		index->x = 0;
		ret = (t_mesh *)ft_realloc(ret, sizeof(t_point ***) * index->y, sizeof(t_point ***) * (index->y + 1));
		ret[(int)(index->y)] = (t_point  *)ft_memalloc(sizeof(t_point *));
		while (parts[(int)index->x])
		{
			ret[(int)(index->y)][(int)(index->x)] = new_point(index->x, index->y, ft_atoi(parts[(int)index->x]));
			ret[(int)(index->y)] = (t_point *)ft_realloc(ret[(int)(index->y)], sizeof(t_point *) * (index->x + 1), sizeof(t_point *) * (index->x + 2));
			index->x++;
		}
		index->y++;
	}
	localize(*ret, index->x, index->y);
	return (ret);
}
