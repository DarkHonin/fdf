/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:11:02 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/26 11:11:07 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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