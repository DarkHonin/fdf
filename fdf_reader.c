/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:50:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/06 12:37:51 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>


t_mesh read_fdf(int fd)
{
	char *line;
	char **parts;
	t_mesh ret;
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
			vect_push(vline, new_point(index->x, index->y, ft_atoi(parts[(int)index->x])));
			index->x++;
		}
		vect_push(ret, vline);
		index->y++;
	}
	return (ret);
}
