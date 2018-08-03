/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_new_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:51:10 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/28 13:51:11 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_choose_next_lvl(t_info *i, SDL_Rect dest_b)
{
	dest_b.y += dest_b.h * 1.2;
	dest_b.h -= dest_b.h / 10;
	if (i->menu.key == 3)
		SDL_RenderCopy(i->img.rend, i->tex.ch_lvl[3], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_ch_lvl[3], NULL, &dest_b);
	dest_b.y += dest_b.h * 1.2;
	dest_b.h -= dest_b.h / 10;
	if (i->menu.key == 4)
		SDL_RenderCopy(i->img.rend, i->tex.ch_lvl[4], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_ch_lvl[4], NULL, &dest_b);
	dest_b.y += dest_b.h * 1.2;
	dest_b.h -= dest_b.h / 10;
	if (i->menu.key == 5)
		SDL_RenderCopy(i->img.rend, i->tex.ch_lvl[5], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_ch_lvl[5], NULL, &dest_b);
}

static	void			ft_choose_lvl(t_info *i)
{
	SDL_Rect	dest_b;

	ft_calc_des(i, &dest_b);
	if (i->menu.key == 0)
		SDL_RenderCopy(i->img.rend, i->tex.ch_lvl[0], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_ch_lvl[0], NULL, &dest_b);
	dest_b.y += dest_b.h * 1.2;
	dest_b.h -= dest_b.h / 10;
	if (i->menu.key == 1)
		SDL_RenderCopy(i->img.rend, i->tex.ch_lvl[1], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_ch_lvl[1], NULL, &dest_b);
	dest_b.y += dest_b.h * 1.2;
	dest_b.h -= dest_b.h / 10;
	if (i->menu.key == 2)
		SDL_RenderCopy(i->img.rend, i->tex.ch_lvl[2], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_ch_lvl[2], NULL, &dest_b);
	ft_choose_next_lvl(i, dest_b);
}

void					ft_submit_lvl(t_info *info)
{
	if (info->menu.key == 0 && info->menu.enter == 1)
		info->lvl = 0;
	else if (info->menu.key == 1 && info->menu.enter == 1)
		info->lvl = 1;
	else if (info->menu.key == 2 && info->menu.enter == 1)
		info->lvl = 2;
	else if (info->menu.key == 3 && info->menu.enter == 1)
		info->lvl = 3;
	else if (info->menu.key == 4 && info->menu.enter == 1)
		info->lvl = 4;
	else if (info->menu.key == 5 && info->menu.enter == 1)
		info->lvl = 5;
	if (info->menu.enter == 1)
	{
		info->menu.enter = 0;
		info->menu.new_game = 0;
		info->flags.menu = 0;
		info->flags.game = 1;
		info->menu.key = 0;
		info->flags.shoot = 0;
		ft_create_minimap(info);
		ft_set_position(info);
	}
}

void					ft_new_game(t_info *info)
{
	ft_choose_lvl(info);
	ft_submit_lvl(info);
}
