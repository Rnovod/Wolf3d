/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:00:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/22 12:00:01 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_turn_right(t_info *info)
{
	double		olddir_x;
	double		oldpl_x;
	double		speed;

	if (info->ev.event.motion.xrel > 0 &&
		info->ev.event.type == SDL_MOUSEMOTION &&
		info->flags.hide_mouse)
		speed = info->ev.event.motion.xrel * -0.004;
	else
		speed = -0.009;
	olddir_x = info->player.d_x;
	info->player.d_x = info->player.d_x * cos(speed) -
	info->player.d_y * sin(speed);
	info->player.d_y = olddir_x * sin(speed) +
	info->player.d_y * cos(speed);
	oldpl_x = info->player.pl_x;
	info->player.pl_x = info->player.pl_x * cos(speed) -
	info->player.pl_y * sin(speed);
	info->player.pl_y = oldpl_x * sin(speed) +
	info->player.pl_y * cos(speed);
}

void					ft_turn_left(t_info *info)
{
	double		olddir_x;
	double		oldpl_x;
	double		speed;

	if (info->ev.event.motion.xrel < 0 &&
		info->ev.event.type == SDL_MOUSEMOTION &&
		info->flags.hide_mouse)
		speed = info->ev.event.motion.xrel * -0.004;
	else
		speed = 0.009;
	olddir_x = info->player.d_x;
	info->player.d_x = info->player.d_x * cos(speed) -
	info->player.d_y * sin(speed);
	info->player.d_y = olddir_x * sin(speed) +
	info->player.d_y * cos(speed);
	oldpl_x = info->player.pl_x;
	info->player.pl_x = info->player.pl_x * cos(speed) -
	info->player.pl_y * sin(speed);
	info->player.pl_y = oldpl_x * sin(speed) +
	info->player.pl_y * cos(speed);
}
