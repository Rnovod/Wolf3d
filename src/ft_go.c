/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:06:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/23 17:06:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_go_left(t_info *info)
{
	double	speed;

	if (info->flags.run == 1)
		speed = 0.08;
	else
		speed = 0.03;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x -
		info->player.pl_x * (speed + 0.5))][(int)(info->player.p_y)] == 0)
		info->player.p_x -= info->player.pl_x * speed;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x)]
		[(int)(info->player.p_y - info->player.pl_y * (speed + 0.5))] == 0)
		info->player.p_y -= info->player.pl_y * speed;
}

void					ft_go_right(t_info *info)
{
	double	speed;

	if (info->flags.run == 1)
		speed = 0.08;
	else
		speed = 0.03;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x +
		info->player.pl_x * (speed + 0.5))][(int)(info->player.p_y)] == 0)
		info->player.p_x += info->player.pl_x * speed;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x)]
		[(int)(info->player.p_y + info->player.pl_y * (speed + 0.5))] == 0)
		info->player.p_y += info->player.pl_y * speed;
}

void					ft_go_forward(t_info *info)
{
	double	speed;

	if (info->flags.run == 1)
		speed = 0.08;
	else
		speed = 0.03;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x +
		info->player.d_x * (speed + 0.5))][(int)(info->player.p_y)] == 0)
		info->player.p_x += info->player.d_x * speed;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x)]
		[(int)(info->player.p_y + info->player.d_y * (speed + 0.5))] == 0)
		info->player.p_y += info->player.d_y * speed;
}

void					ft_go_back(t_info *info)
{
	double	speed;

	if (info->flags.run == 1)
		speed = 0.08;
	else
		speed = 0.03;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x -
		info->player.d_x * (speed + 0.5))][(int)(info->player.p_y)] == 0)
		info->player.p_x -= info->player.d_x * speed;
	if (info->map[info->lvl].matrix[(int)(info->player.p_x)]
		[(int)(info->player.p_y - info->player.d_y * (speed + 0.5))] == 0)
		info->player.p_y -= info->player.d_y * speed;
}
