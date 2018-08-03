/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:29:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/27 18:29:20 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_set_position(t_info *info)
{
	info->player.d_x = -1;
	info->player.d_y = 0;
	info->player.pl_x = 0;
	info->player.pl_y = 0.66;
	info->player.p_x = info->map[info->lvl].player_x + 0.5;
	info->player.p_y = info->map[info->lvl].player_y + 0.5;
}
