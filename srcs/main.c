/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:20:37 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 12:44:46 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <3dft.h>

int	event_handle(void *e)
{
	return (1);
}

void render(t_map *map)
{
	t_stage *st;
	t_value_v p;
	t_vect4		q;
	
	st = get_stage();
	for (t_len i = 0; i < map->size[1]; i++)
	{
		q[0] = ((i % map->size[0]));
		q[1] = ((i / map->size[0]));
		q[2] = map->points[i];
		q[3] = 1;
		q[0] *= MESH_SPREAD;
		q[1] *= MESH_SPREAD;
		p = space_to_canvas(*(st->global_space), q);
		matrix_rotate_global(p, map->rotation);
		p[0] += (WINDOW_C_W);
		p[1] += (WINDOW_C_H);
		put_pixel(p, (t_color){255 * map->points[i], 255, 255});
	}
}

void roate_space(t_space *s, t_value_v ang)
{
	t_value_m mtr;
	t_value_m hold;
	t_mtr_config cfg;
	t_len i;
	t_len q;
	
	mtr = create_value_m(ROT_MATRIX_SIZE);
	i = 0;
	while (i < Z_AXIS + 1)
	{
		cfg = matrix_config_provider(i);
		cfg(mtr, ang[i]);
		log_value_m(mtr, (t_size){3, 3});
		hold = matrix_multiply(s->components, mtr, ROT_MATRIX_SIZE, ROT_MATRIX_SIZE);
		q = 0;
		while (q < 3)
		{
			vect_set(s->components[q], hold[q], 3);
			q++;
		}
		log_value_m(s->components, (t_size){4, 4});
		i++;
	}
	log_value_m(s->components, (t_size){4, 4});
}

int key_event(int keycode, void *e)
{
	clean();
	if (keycode == SDLK_w)
		get_stage()->camera_space->components[SPACE_C_T][2]++;
	if (keycode == SDLK_s)
		get_stage()->camera_space->components[SPACE_C_T][2]--;
	if (keycode == SDLK_a)
		roate_space(get_stage()->global_space, (t_vect){DEG_RAD(1), 0, 0});
	if (keycode == SDLK_d)
		roate_space(get_stage()->global_space, (t_vect){DEG_RAD(-1), 0, 0});
	if (keycode == SDLK_q)
		roate_space(get_stage()->global_space, (t_vect){0, DEG_RAD(1), 0});
	if (keycode == SDLK_e)
		roate_space(get_stage()->global_space, (t_vect){0, DEG_RAD(-1), 0});
	if (keycode == SDLK_z)
		roate_space(get_stage()->global_space, (t_vect){0, 0, DEG_RAD(1)});
	if (keycode == SDLK_c)
		roate_space(get_stage()->global_space, (t_vect){0, 0, DEG_RAD(-1)});
	
	get_stage()->camera_space->inverse = matrix_inverse(get_stage()->camera_space->components, SPACE_COMPONENT_SIZE);
	render(e);
	flip();
	return (1);
}

int	loop(void *arg)
{
	return (1);
}

int main(int ac, char **av)
{
	char		*filename;
	t_map 		*map;
	space_set((get_stage()->camera_space), SPACE_C_T, (t_vect){0, 0, -5, 1});
	if (ac != 2)
		file_error("Invalid number of arguments");
	filename = av[1];
	map = fdf_read_file(filename);
	get_window();
	start_loop(&loop, map);
	return (1);
}