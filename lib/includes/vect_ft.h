/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 21:42:27 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/23 14:01:16 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT_FT_H
# define VECT_FT_H

# include <libft.h>

# define MAKE_VECT(data_size) ft_buffnew(0, data_size)

typedef	t_buff t_vector;

void			*vect_pop(t_vector *e);
void			vect_push(t_vector *e, void *data);
void			*vect_pull(t_vector *e);
void			vect_insert(t_vector *e, void *data, int index);
void			*vect_slice(t_vector *e, int index);
void			*vect_get(t_vector *e, int index);

void			vect_dump(t_vector *e);
void			*vect_get_shallow(t_vector *e, int index);
void			*vect_get_next(t_vector *e);
void			vect_itter(t_vector *e, void *meta, void (*f)(t_vector *, void *, void *));
unsigned int	vect_len(t_vector* a);
void            *vect_to_list(t_vector* a);

#endif
