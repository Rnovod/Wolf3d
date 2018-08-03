/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texturing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:36:46 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/27 17:36:47 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	int				ft_choose_wall(t_info *info, t_raycast *t)
{
	int			num;
	int			n;

	num = info->map[info->lvl].matrix[t->map_x][t->map_y] - 1;
	if (info->lvl == 0 && !info->map_name)
		return (num % 2 + 6);
	if (info->lvl == 1 || info->lvl == 2)
		return (num);
	if (t->side == 0 && t->ray_dx < 0)
		n = 0;
	else if (t->side == 1 && t->ray_dy < 0)
		n = 1;
	else if (t->side == 0 && t->ray_dx > 0)
		n = 2;
	else
		n = 3;
	return ((num + n) % 18);
}

static	void			ft_draw_line(t_info *info, t_raycast *t, int n, int x)
{
	int			y;
	int			d;
	int			color;
	int			tex_x;
	int			tex_y;

	tex_x = (int)(t->wall_x * (double)info->surf.w[n]->w);
	tex_x = info->surf.w[n]->w - tex_x - 1;
	y = t->start_y;
	while (y < t->end_y)
	{
		d = y * 256 - info->win.height * 128 + t->line_h * 128;
		tex_y = ((d * info->surf.w[n]->h) / t->line_h) / 256;
		color = ft_coloring(info->surf.w[n], tex_y, tex_x);
		ft_draw_pixel(info, x, y, color);
		y++;
	}
}

void					ft_texturing(t_info *info, t_raycast *t, int x)
{
	int			n;

	n = ft_choose_wall(info, t);
	if (t->side == 0)
		t->wall_x = info->player.p_y + t->wall_dis * t->ray_dy;
	else
		t->wall_x = info->player.p_x + t->wall_dis * t->ray_dx;
	t->wall_x -= floor((t->wall_x));
	ft_draw_line(info, t, n, x);
}
