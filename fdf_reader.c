/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:15:13 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/10 15:26:29 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>


t_fdf_data  *read_fdf(int fd)
{
    t_fdf_data  *data;
    char        *line;
    char        **points;
    int         x;
    int         y;
    
    if (fd < 0 || !(mk_fdf_data(&data)))
        return (NULL);
    printf("Ready to start file read\n");
    y = 0;
    while (get_next_line(fd, &line))
    {
        x = 0;
        ft_putchar('>');
        ft_putendl(line);
        points = ft_strsplit(line, ' ');
        while (points[x])
        {
            add_point(data, mk_fdf_point(x, y, points[x]));
            x++;
        }
        y++;
    }
    return (data);
}

