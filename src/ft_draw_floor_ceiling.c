/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fl_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:35:51 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/27 17:35:52 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_draw_fl_sky(t_info *i, t_raycast *t,
								t_fl_sky *f, int x)
{
	double		cur_dis;
	double		weight;
	int			y;
	int			color;
	int			n;

	n = i->lvl;
	if (t->end_y < 0)
		t->end_y = i->win.height;
	y = t->end_y;
	while (++y < i->win.height)
	{
		cur_dis = i->win.height / (2.0 * y - i->win.height);
		weight = (cur_dis - f->dis_player) / (f->dis_w - f->dis_player);
		f->cur_fl_x = weight * f->fl_x_w + (1.0 - weight) * i->player.p_x;
		f->cur_fl_y = weight * f->fl_y_w + (1.0 - weight) * i->player.p_y;
		f->fl_tex_x = (int)(f->cur_fl_x * i->surf.fl[n]->w) % i->surf.fl[n]->w;
		f->fl_tex_y = (int)(f->cur_fl_y * i->surf.fl[n]->h) % i->surf.fl[n]->h;
		color = ft_coloring(i->surf.fl[n], f->fl_tex_y, f->fl_tex_x);
		ft_draw_pixel(i, x, y, color);
		color = ft_coloring(i->surf.cei[n], f->fl_tex_y, f->fl_tex_x);
		ft_draw_pixel(i, x, i->win.height - y, color);
	}
}

void					ft_find_fl_sky(t_info *info, t_raycast *t, int x)
{
	t_fl_sky	f;

	if (t->side == 0 && t->ray_dx > 0)
	{
		f.fl_x_w = t->map_x;
		f.fl_y_w = t->map_y + t->wall_x;
	}
	else if (t->side == 0 && t->ray_dx < 0)
	{
		f.fl_x_w = t->map_x + 1.0;
		f.fl_y_w = t->map_y + t->wall_x;
	}
	else if (t->side == 1 && t->ray_dy > 0)
	{
		f.fl_x_w = t->map_x + t->wall_x;
		f.fl_y_w = t->map_y;
	}
	else
	{
		f.fl_x_w = t->map_x + t->wall_x;
		f.fl_y_w = t->map_y + 1.0;
	}
	f.dis_w = t->wall_dis;
	f.dis_player = 0.0;
	ft_draw_fl_sky(info, t, &f, x);
}
