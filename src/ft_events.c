/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:09:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 16:09:34 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_change_flags(t_info *info)
{
	if (info->flags.shoot != 0)
		info->flags.shoot++;
	info->flame++;
	if (info->flame > 100)
		info->flame = 0;
	if (info->flags.blink_eyes > 350)
		info->flags.blink_eyes = 0;
	info->flags.blink_eyes++;
}

static	void			ft_do_flags(t_info *info)
{
	if (info->flags.forward == 1)
		ft_go_forward(info);
	if (info->flags.back == 1)
		ft_go_back(info);
	if (info->flags.turn_l == 1)
		ft_turn_left(info);
	if (info->flags.turn_r == 1)
		ft_turn_right(info);
	if (info->flags.go_left == 1)
		ft_go_left(info);
	if (info->flags.go_right == 1)
		ft_go_right(info);
}

static	void			ft_create_game(t_info *info)
{
	ft_do_flags(info);
	ft_create_walls(info);
	SDL_RenderCopy(info->img.rend, info->tex.walls, NULL, NULL);
	ft_put_panel(info);
	ft_put_face(info);
	ft_put_tex_gun(info);
	ft_put_minimap(info);
	ft_change_flags(info);
}

void					ft_events(t_info *info)
{
	while (!info->ev.close_requested)
	{
		while (SDL_PollEvent(&info->ev.event))
		{
			if (info->ev.event.type == SDL_QUIT)
				info->ev.close_requested = 1;
			ft_event_window(info);
			if (info->flags.close_win == 0)
			{
				ft_event_mouse(info);
				ft_event_keyboard(info);
			}
		}
		if (info->flags.close_win == 0)
		{
			SDL_RenderClear(info->img.rend);
			if (info->flags.menu == 1)
				ft_create_menu(info);
			else
				ft_create_game(info);
			SDL_RenderPresent(info->img.rend);
		}
	}
}
