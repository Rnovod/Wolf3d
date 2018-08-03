/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:21:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/30 21:21:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_calc_des(t_info *info, SDL_Rect *dest_b)
{
	int			size_w;
	int			size_h;

	size_w = info->win.width / 8;
	size_h = info->win.height / 18;
	dest_b->x = info->win.width / 2 - size_w / 2;
	dest_b->y = info->win.height / 2 - size_h * 2;
	dest_b->w = size_w;
	dest_b->h = size_h;
}

static	void			ft_put_next_buttons(t_info *i, SDL_Rect dest_b)
{
	dest_b.y += dest_b.h;
	dest_b.h -= dest_b.h / 8;
	if (i->menu.key == 2)
		SDL_RenderCopy(i->img.rend, i->tex.choose[2], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_choose[2], NULL, &dest_b);
	dest_b.y += dest_b.h * 1.2;
	dest_b.h -= dest_b.h / 6;
	if (i->menu.key == 3)
		SDL_RenderCopy(i->img.rend, i->tex.choose[3], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_choose[3], NULL, &dest_b);
}

static	void			ft_put_buttons(t_info *i)
{
	SDL_Rect	dest_b;

	ft_calc_des(i, &dest_b);
	if (i->flags.game == 1)
	{
		if (i->menu.key == 0)
			SDL_RenderCopy(i->img.rend, i->tex.choose[0], NULL, &dest_b);
		else
			SDL_RenderCopy(i->img.rend, i->tex.no_choose[0], NULL, &dest_b);
	}
	dest_b.y += dest_b.h * 1.2;
	dest_b.h -= dest_b.h / 10;
	if (i->menu.key == 1)
		SDL_RenderCopy(i->img.rend, i->tex.choose[1], NULL, &dest_b);
	else
		SDL_RenderCopy(i->img.rend, i->tex.no_choose[1], NULL, &dest_b);
	ft_put_next_buttons(i, dest_b);
}

static	void			ft_press_button(t_info *info)
{
	if (info->menu.key == 0 && info->menu.enter == 1)
		info->flags.menu = 0;
	else if (info->menu.key == 1 && info->menu.enter == 1)
	{
		info->menu.key = 0;
		info->menu.new_game = 1;
	}
	else if (info->menu.key == 2 && info->menu.enter == 1)
		info->menu.option = 1;
	else if (info->menu.key == 3 && info->menu.enter == 1)
	{
		info->ev.event.type = SDL_QUIT;
		SDL_PushEvent(&info->ev.event);
	}
	if (info->menu.enter == 1)
		info->menu.enter = 0;
}

void					ft_create_menu(t_info *info)
{
	SDL_Rect	dest_menu;

	dest_menu.x = 0;
	dest_menu.y = 0;
	dest_menu.w = info->win.width;
	dest_menu.h = info->win.height;
	if (info->menu.option == 0)
		SDL_RenderCopy(info->img.rend, info->tex.menu[0], NULL, &dest_menu);
	else
		SDL_RenderCopy(info->img.rend, info->tex.menu[1], NULL, &dest_menu);
	if (info->menu.option == 0 && info->menu.new_game == 0)
	{
		if (info->flags.game == 0 && info->menu.key == 0)
			info->menu.key = 1;
		ft_put_buttons(info);
		ft_press_button(info);
	}
	else if (info->menu.new_game == 1)
		ft_new_game(info);
}
