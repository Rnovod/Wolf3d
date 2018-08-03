/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:31:45 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/17 16:31:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_calc_ray_pos_dis(t_info *info, t_raycast *t, int x)
{
	double	cam_x;

	cam_x = 2 * x / ((double)info->win.width) - 1;
	t->ray_dx = info->player.d_x + info->player.pl_x * cam_x;
	t->ray_dy = info->player.d_y + info->player.pl_y * cam_x;
	t->map_x = (int)info->player.p_x;
	t->map_y = (int)info->player.p_y;
	t->delta_dx = sqrt(1 + (t->ray_dy * t->ray_dy) / (t->ray_dx * t->ray_dx));
	t->delta_dy = sqrt(1 + (t->ray_dx * t->ray_dx) / (t->ray_dy * t->ray_dy));
}

void					ft_step(t_info *info, t_raycast *t)
{
	if (t->ray_dx < 0)
	{
		t->step_x = -1;
		t->side_dis_x = (info->player.p_x - t->map_x) * t->delta_dx;
	}
	else
	{
		t->step_x = 1;
		t->side_dis_x = (t->map_x + 1.0 - info->player.p_x) * t->delta_dx;
	}
	if (t->ray_dy < 0)
	{
		t->step_y = -1;
		t->side_dis_y = (info->player.p_y - t->map_y) * t->delta_dy;
	}
	else
	{
		t->step_y = 1;
		t->side_dis_y = (t->map_y + 1.0 - info->player.p_y) * t->delta_dy;
	}
}

void					ft_hit(t_info *info, t_raycast *t)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (t->side_dis_x < t->side_dis_y)
		{
			t->side_dis_x += t->delta_dx;
			t->map_x += t->step_x;
			t->side = 0;
		}
		else
		{
			t->side_dis_y += t->delta_dy;
			t->map_y += t->step_y;
			t->side = 1;
		}
		if (info->map[info->lvl].matrix[t->map_x][t->map_y] > 0)
			hit = 1;
	}
}

void					ft_calc_dis_proj(t_info *info, t_raycast *t)
{
	if (t->side == 0)
		t->wall_dis = (t->map_x - info->player.p_x +
			(1 - t->step_x) / 2) / t->ray_dx;
	else
		t->wall_dis = (t->map_y - info->player.p_y +
			(1 - t->step_y) / 2) / t->ray_dy;
	t->line_h = (int)(info->win.height / t->wall_dis);
	t->start_y = -t->line_h / 2 + info->win.height / 2;
	if (t->start_y < 0)
		t->start_y = 0;
	t->end_y = t->line_h / 2 + info->win.height / 2;
	if (t->end_y >= info->win.height)
		t->end_y = info->win.height - 1;
}

void					ft_raycasting(t_info *info)
{
	t_raycast	t;
	int			x;

	x = 0;
	while (x < info->win.width)
	{
		ft_calc_ray_pos_dis(info, &t, x);
		ft_step(info, &t);
		ft_hit(info, &t);
		ft_calc_dis_proj(info, &t);
		ft_texturing(info, &t, x);
		ft_find_fl_sky(info, &t, x);
		x++;
	}
}
