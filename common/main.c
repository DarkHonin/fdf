/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:20:37 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/26 15:32:19 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <3dft.h>

int	event_handle(void *e)
{
	return (1);
}

static void	set_point(t_len i, t_map *map, t_value_v point)
{
	log_state(INFO, "Configureing point", &set_point);
	point[0] = ((i % map->size[0])) * MESH_SPREAD;
	point[1] = (i / map->size[0]) * MESH_SPREAD;
	point[2] = map->points[i] * MESH_SPREAD;
	point[3] = 1;
	log_state(INFO, "Configured point", &set_point);
}

void render(t_map *map)
{
	t_stage 	*st;
	t_vect4		pnt;
	t_value_v	screen;
	t_value_v	last;
	t_len		i;

	st = get_stage();
	i = 0;
	log_state(INFO, "Starting render sycle", &render);
	while (i < map->size[1])
	{
		set_point(i, map, pnt);
		log_value_v(pnt, 3);
		if (pnt[0] == 0)
			last = NULL;
		pnt[0] -= ((map->size[0]) / 2) * MESH_SPREAD;
		screen = space_to_canvas(*get_stage()->global_space, pnt);
		if (screen == NULL)
		{
			i++;
			continue;
		}
		screen[0] += WINDOW_C_W;
		screen[1] += WINDOW_C_H;
		log_value_v(screen, 2);
		if (last)
			draw_line(screen, last, (t_color){map->points[i] * 255, 255, 0}, 2);
		put_pixel(screen, (t_color){map->points[i] * 255, 255, 0});
		if (screen)
			last = screen;
		i++;
	}
	log_state(INFO, "Finished render sycle", &render);
}

void roate_space(t_space *s, t_value_v ang)
{
	t_value_m mtr;
	t_value_m hold;
	t_mtr_config cfg;
	t_len i;
	t_len q;
	
	log_state(INFO, "Starting space rotate", &render);
	mtr = create_value_m(ROT_MATRIX_SIZE);
	i = 0;
	while (i < Z_AXIS + 1)
	{
		cfg = matrix_config_provider(i);
		cfg(mtr, ang[i]);
		hold = matrix_multiply(((t_space_empty *)s)->components, mtr, ROT_MATRIX_SIZE, ROT_MATRIX_SIZE);
		q = 0;
		while (q < 3)
		{
			vect_set(((t_space_empty *)s)->components[q], hold[q], 3);
			q++;
		}
		i++;
	}
	log_state(INFO, "Finished space rotate", &render);
}

int	loop(void *arg)
{
	return (1);
}

int main(int ac, char **av)
{
	char		*filename;
	t_map 		*map;

	space_set((get_stage()->camera_space), SPACE_C_T, (t_vect){0, 0, 5, 1});
	if (ac != 2)
		file_error("Invalid number of arguments");
	filename = av[1];
	map = fdf_read_file(filename);
	get_window();
	start_loop(&loop, map);
	return (1);
}