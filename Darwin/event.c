/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:08:49 by wgourley          #+#    #+#             */
/*   Updated: 2018/09/26 15:20:19 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int key_event(int keycode, void *e)
{
    printf("%i\n", keycode);
	clean();
	get_stage()->camera_space->SPACE_EMPTY.components[SPACE_C_T][2] += (keycode == KEY_W) * 0.1;
	get_stage()->camera_space->SPACE_EMPTY.components[SPACE_C_T][2] -= keycode == KEY_S;
	if (keycode == KEY_A)
		roate_space(get_stage()->global_space, (t_vect){DEG_RAD(1), 0, 0});
	if (keycode == KEY_D)
		roate_space(get_stage()->global_space, (t_vect){DEG_RAD(-1), 0, 0});
	if (keycode == KEY_Q)
		roate_space(get_stage()->global_space, (t_vect){0, DEG_RAD(1), 0});
	if (keycode == KEY_E)
		roate_space(get_stage()->global_space, (t_vect){0, DEG_RAD(-1), 0});
	if (keycode == KEY_Z)
		roate_space(get_stage()->global_space, (t_vect){0, 0, DEG_RAD(1)});
	if (keycode == KEY_C)
		roate_space(get_stage()->global_space, (t_vect){0, 0, DEG_RAD(-1)});
	if (keycode == KEY_ESC)
        close_window();
	get_stage()->camera_space->SPACE_EMPTY.inverse = matrix_inverse(get_stage()->camera_space->SPACE_EMPTY.components, SPACE_COMPONENT_SIZE);
	render(e);
	flip();
	return (1);
}