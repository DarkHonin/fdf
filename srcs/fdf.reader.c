/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:18:28 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/25 12:18:28 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fcntl.h>

static t_len add_points(t_value_v *lst, t_len l, char **s)
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

t_map	*fdf_read_file(char *file)
{
	int	fd;
	char *line;
	char **sub;
	t_len ll[3];
	t_map *ret;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		file_error("no such file");
	log_state(LOG, "STARTING FILE READ", &fdf_read_file);
	ll[1] = 0;
	ll[2] = 0;
	ret = ft_memalloc(sizeof(t_map));
	ret->points = create_value_v(0);
	while (get_next_line(fd, &line) > 0)
	{
		ll[0] = 0;
		sub = ft_strsplit(line, ' ');
		ll[0] = add_points(&ret->points, ll[2], sub);
		if (ll[1] == 0)
			ll[1] = ll[0];
		if (ll[0] != ll[1])
			file_error("row length invalid");
		free(line);
		ll[2] += ll[0];
	}

	log_state(LOG, "FILE READ COMPLETE", &fdf_read_file);
	ret->size[0] = ll[1];
	ret->size[1] = ll[2];
	return (ret);
}