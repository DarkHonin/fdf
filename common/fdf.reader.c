/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:18:28 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/26 11:53:05 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fcntl.h>

static t_len	add_points(t_value_v *lst, t_len l, char **s)
{
	t_len c;

	c = 0;
	while (*s)
	{
		append_to_value_v(lst, l + c, ft_atoi(*s));
		c++;
		free(*s);
		s++;
	}
	log_state(LOG, "APPENDED ROW", &add_points);
	return (c);
}

static int		open_file(char *fn)
{
	int fd;

	fd = open(fn, O_RDONLY);
	if (fd <= 0)
		file_error("no such file");
	return (fd);
}

static int		read(t_map *ret, int fd)
{
	t_len	ll[2];
	char	*line;
	char	**sub;

	ll[1] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ll[0] = 0;
		sub = ft_strsplit(line, ' ');
		ll[0] = add_points(&ret->points, ret->size[1], sub);
		free(sub);
		if (ll[1] == 0)
			ll[1] = ll[0];
		if (ll[0] != ll[1])
			file_error("row length invalid");
		free(line);
		ret->size[1] += ll[0];
	}
	free(line);
	return (ll[1]);
}

t_map			*fdf_read_file(char *file)
{
	int		fd;
	t_map	*ret;

	fd = open_file(file);
	log_state(LOG, "STARTING FILE READ", &fdf_read_file);
	ret = ft_memalloc(sizeof(t_map));
	ret->size[1] = 0;
	ret->points = create_value_v(0);
	ret->size[0] = read(ret, fd);
	log_state(LOG, "FILE READ COMPLETE", &fdf_read_file);
	return (ret);
}
