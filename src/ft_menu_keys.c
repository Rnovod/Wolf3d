/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:47:48 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/31 12:47:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_change_key(t_info *info)
{
	if (info->menu.new_game == 1)
	{
		if (info->menu.key > 5)
			info->menu.key = 0;
		else if (info->menu.key < 0)
			info->menu.key = 5;
	}
	else
	{
		if (info->menu.key > 3)
			info->menu.key = 0;
		else if (info->menu.key < 0 ||
				(info->flags.game == 0 && info->menu.key == 0))
			info->menu.key = 3;
	}
}

void					ft_press_menu_keys(t_info *info)
{
	if (info->ev.event.key.keysym.sym == SDLK_UP)
		info->menu.key--;
	else if (info->ev.event.key.keysym.sym == SDLK_DOWN)
		info->menu.key++;
	else if (info->ev.event.key.keysym.sym == SDLK_RETURN)
		info->menu.enter = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_ESCAPE)
	{
		if (info->menu.option == 1)
			info->menu.option = 0;
		else if (info->menu.new_game == 1)
			info->menu.new_game = 0;
		else
		{
			info->ev.event.type = SDL_QUIT;
			SDL_PushEvent(&info->ev.event);
		}
	}
	ft_change_key(info);
}

void					ft_unpress_menu_keys(t_info *info)
{
	if (info->ev.event.key.keysym.sym == SDLK_RETURN)
		info->menu.enter = 0;
}
