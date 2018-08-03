/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_default_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:05:48 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 21:05:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_set_null_guns(t_info *info)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		info->tex.knife[i] = NULL;
		info->tex.pistol[i] = NULL;
		info->tex.machine[i] = NULL;
		info->tex.minigun[i] = NULL;
		info->tex.flameth[i] = NULL;
		info->tex.bazuka[i] = NULL;
		i++;
	}
	info->tex.knife[i] = NULL;
	info->tex.flameth[i] = NULL;
	info->tex.bazuka[i] = NULL;
}

static	void			ft_set_null_menu(t_info *info)
{
	int		i;

	info->tex.menu[0] = NULL;
	info->tex.menu[1] = NULL;
	i = 0;
	while (i < 4)
	{
		info->tex.choose[i] = NULL;
		info->tex.no_choose[i] = NULL;
		info->tex.ch_lvl[i] = NULL;
		info->tex.no_ch_lvl[i] = NULL;
		info->tex.face[i] = NULL;
		i++;
	}
	while (i < 7)
	{
		info->tex.ch_lvl[i] = NULL;
		info->tex.no_ch_lvl[i] = NULL;
		i++;
	}
}

static	void			ft_set_null_walls(t_info *info)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		info->surf.fl[i] = NULL;
		info->surf.cei[i] = NULL;
		info->surf.w[i] = NULL;
		i++;
	}
	while (i < 18)
	{
		info->surf.w[i] = NULL;
		i++;
	}
	info->surf.minimap = NULL;
}

static	void			ft_set_flags(t_info *info)
{
	info->flags.shoot = 0;
	info->flags.turn_r = 0;
	info->flags.turn_l = 0;
	info->flags.back = 0;
	info->flags.forward = 0;
	info->flags.go_right = 0;
	info->flags.go_left = 0;
	info->flags.blink_eyes = 0;
	info->flags.hide_mouse = 0;
	info->flags.run = 0;
	info->flags.menu = 1;
	info->flags.game = 0;
	info->flags.creater = 0;
	info->flags.close_win = 0;
	info->menu.option = 0;
	info->menu.enter = 0;
	info->menu.new_game = 0;
	info->menu.key = 0;
}

void					ft_set_default_info(t_info *info)
{
	info->img.data.arr = NULL;
	info->img.m_map.arr = NULL;
	info->music_file = NULL;
	info->map_name = NULL;
	info->win.win = NULL;
	info->img.rend = NULL;
	info->tex.walls = NULL;
	ft_set_null_map(info);
	ft_set_null_walls(info);
	ft_set_null_menu(info);
	ft_set_null_guns(info);
	ft_set_flags(info);
	info->tex.panel = NULL;
	info->win.width = 700;
	info->win.height = 700;
	info->a.audio_buf = NULL;
	info->ev.close_requested = 0;
	info->lvl = 0;
	info->gun = 1;
	info->flame = 0;
}
