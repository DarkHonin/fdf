/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgourley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 11:56:58 by wgourley          #+#    #+#             */
/*   Updated: 2018/07/27 12:19:22 by wgourley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

void	init_error(char *msg)
{
	ft_putstr("\e[91mFailed on init:\e[0m ");
	ft_putendl(msg);
	exit(1);
}