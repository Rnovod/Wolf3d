/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:02:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/17 18:02:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_choose_gun(t_info *info)
{
	info->flags.shoot = 0;
	if (info->ev.event.key.keysym.sym == SDLK_1)
		info->gun = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_2)
		info->gun = 2;
	else if (info->ev.event.key.keysym.sym == SDLK_3)
		info->gun = 3;
	else if (info->ev.event.key.keysym.sym == SDLK_4)
		info->gun = 4;
	else if (info->ev.event.key.keysym.sym == SDLK_5)
		info->gun = 5;
	else if (info->ev.event.key.keysym.sym == SDLK_6)
		info->gun = 6;
}

static	void			ft_move_player(t_info *info)
{
	if (info->ev.event.key.keysym.sym == SDLK_w)
		info->flags.forward = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_s)
		info->flags.back = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_d)
		info->flags.go_right = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_a)
		info->flags.go_left = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_q)
		info->flags.turn_l = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_e)
		info->flags.turn_r = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_LSHIFT)
		info->flags.run = 1;
}

static	void			ft_unpress_key(t_info *info)
{
	if (info->ev.event.key.keysym.sym == SDLK_a)
		info->flags.go_left = 0;
	else if (info->ev.event.key.keysym.sym == SDLK_d)
		info->flags.go_right = 0;
	else if (info->ev.event.key.keysym.sym == SDLK_w)
		info->flags.forward = 0;
	else if (info->ev.event.key.keysym.sym == SDLK_s)
		info->flags.back = 0;
	else if (info->ev.event.key.keysym.sym == SDLK_e)
		info->flags.turn_r = 0;
	else if (info->ev.event.key.keysym.sym == SDLK_q)
		info->flags.turn_l = 0;
	else if (info->ev.event.key.keysym.sym == SDLK_LSHIFT)
		info->flags.run = 0;
	if (info->ev.event.key.keysym.sym == SDLK_RETURN)
		info->menu.enter = 0;
}

static	void			ft_press_key(t_info *info)
{
	if (info->ev.event.key.keysym.sym == SDLK_ESCAPE)
		info->flags.menu = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_KP_PLUS)
		ft_create_audio(info, info->music_file);
	else if (info->ev.event.key.keysym.sym == SDLK_KP_MINUS)
		ft_create_audio(info, "./music/2.wav");
	else if ((info->ev.event.key.keysym.sym >= 97 &&
		info->ev.event.key.keysym.sym <= 122) ||
		info->ev.event.key.keysym.sym == SDLK_LSHIFT)
		ft_move_player(info);
	else if (info->ev.event.key.keysym.sym >= SDLK_KP_1 &&
		info->ev.event.key.keysym.sym <= SDLK_KP_0 && info->flags.creater == 1)
		ft_change_lvl(info);
	else if (info->ev.event.key.keysym.sym >= 0x30 &&
		info->ev.event.key.keysym.sym <= 0x36)
		ft_choose_gun(info);
	else if (info->ev.event.key.keysym.sym == SDLK_F19)
	{
		if (info->flags.creater == 1)
			info->flags.creater = 0;
		else
			info->flags.creater = 1;
	}
}

void					ft_event_keyboard(t_info *info)
{
	if (info->ev.event.type == SDL_KEYDOWN)
	{
		if (info->flags.menu == 1)
			ft_press_menu_keys(info);
		else
			ft_press_key(info);
	}
	else if (info->ev.event.type == SDL_KEYUP)
	{
		if (info->flags.menu == 1)
			ft_unpress_menu_keys(info);
		else
			ft_unpress_key(info);
	}
}
