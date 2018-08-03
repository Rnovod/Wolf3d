/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:08:25 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/20 14:08:25 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_create_walls(t_info *info)
{
	ft_clear_data(info);
	ft_raycasting(info);
	ft_create_tex_data(info);
}
