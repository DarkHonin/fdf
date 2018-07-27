/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:52:38 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 12:09:08 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_W 800
# define WINDOW_H 600
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define MESH_SPREAD 10
# define KEY_PLUS 69
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_MINUS 78
# define DEG_RAD(x) ((x * M_PI) / 180)
# define RAD_DEG(x) ((x * 180) / M_PI)

# include <mlx.h>
# include <libft.h>

typedef struct	s_window
{
	void	*window_pointer;
	void	*context;
}				t_window;

void		init_error(char *msg);
t_window	*get_window();
void		close_window();

#endif