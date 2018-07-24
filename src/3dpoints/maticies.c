/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maticies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:15:44 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/24 12:08:03 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <3d_point.h>
#include <math.h>

t_matrix *get_rot_matrix_x(float deg)
{
	static t_matrix *mat = NULL;

	if (mat == NULL)
		mat = new_matrix(3, 3);
	mat->cells[2][2] = 1;
	mat->cells[0][0] = cos((deg / 180) * M_PI);
	mat->cells[0][1] = -sin((deg / 180) * M_PI);

	mat->cells[1][1] = cos((deg / 180) * M_PI);
	mat->cells[1][0] = sin((deg / 180) * M_PI);
	return (mat);
}

t_matrix *get_rot_matrix_y(float deg)
{
	static t_matrix *mat = NULL;

	if (mat == NULL)
		mat = new_matrix(3, 3);
	mat->cells[1][1] = 1;
	mat->cells[0][0] = cos((deg / 180) * M_PI);
	mat->cells[0][2] = sin((deg / 180) * M_PI);

	mat->cells[2][2] = cos((deg / 180) * M_PI);
	mat->cells[2][0] = -sin((deg / 180) * M_PI);
	return (mat);
}

t_matrix *get_rot_matrix_z(float deg)
{
	static t_matrix *mat = NULL;

	if (mat == NULL)
		mat = new_matrix(3, 3);
	mat->cells[0][0] = 1;
	mat->cells[1][1] = cos((deg / 180) * M_PI);
	mat->cells[1][2] = -sin((deg / 180) * M_PI);

	mat->cells[2][2] = cos((deg / 180) * M_PI);
	mat->cells[2][1] = sin((deg / 180) * M_PI);
	return (mat);
}