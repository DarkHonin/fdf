/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:15:18 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 12:19:00 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.sdl.h>
#include <stdlib.h>

void	file_error(char *msg)
{
	ft_putstr("\e[91mInvalid file:\e[0m ");
	ft_putendl(msg);
	exit(1);
}