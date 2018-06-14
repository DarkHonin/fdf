/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:50:59 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/14 08:09:27 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>

t_mesh	*read_fdf(int fd)
{
	char *line;
	char **parts;
	t_mesh *ret;
	
	while (get_next_line(fd, &line))
	{
		ft_putstr(">> ");
		ft_putendl(line);
		parts = ft_strsplit(line, ' ');
	}

	return (ret);
}