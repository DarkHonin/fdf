/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 23:53:16 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/14 11:45:40 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_FT_H
# define MATRIX_FT_H

#include <libft.h>

typedef struct	s_matrix
{
	float			**cells;
	unsigned int	rows;
	unsigned int	cols;
}				t_matrix;

typedef unsigned int t_coor;

t_matrix	*new_matrix(t_coor rows, t_coor cols);
void		del_matrix(t_matrix **del);
void		print_matrix(t_matrix *mtr);
float		*get_row(t_matrix *mtr, t_coor r);
float		**get_col(t_matrix *mtr, t_coor c);
void		set_cell(t_matrix *mtr, t_coor r, t_coor c, float p);
void		matrix_valid_multiple(t_matrix *m1, t_matrix *m2);
float		matrix_rc_prod(t_matrix *m1, t_matrix *m2, t_coor c, t_coor r);
t_matrix	*matrix_prod(t_matrix *m1, t_matrix *m2);

#endif