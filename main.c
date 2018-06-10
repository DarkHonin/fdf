/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:06:21 by wgourley          #+#    #+#             */
/*   Updated: 2018/06/10 15:43:13 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *filename;
    int   fd;
    t_fdf_data  *data;
    void    *context;
    if (argc < 2)
        return (-1);
    filename = argv[argc - 1];
    printf("Filename: %s\n", filename);
    fd = open(filename, O_RDONLY);
    data = read_fdf(fd);
    print_fdf(data);

    context = mlx_init();

    return (0);
}