/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:01:21 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/17 18:01:22 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_motion(t_info *info)
{
	if (info->flags.hide_mouse == 1)
	{
		if (info->ev.event.motion.xrel > 0)
			ft_turn_right(info);
		if (info->ev.event.motion.xrel < 0)
			ft_turn_left(info);
	}
}

static	void			ft_hide_mouse(t_info *info)
{
	if (info->flags.hide_mouse == 1)
		info->flags.hide_mouse = 0;
	else
		info->flags.hide_mouse = 1;
	if (info->flags.hide_mouse)
		if (SDL_SetRelativeMouseMode(SDL_TRUE) < 0)
			ft_error(info, 0);
	if (!info->flags.hide_mouse)
		if (SDL_SetRelativeMouseMode(SDL_FALSE) < 0)
			ft_error(info, 0);
}

void					ft_event_mouse(t_info *info)
{
	if (info->ev.event.type == SDL_MOUSEMOTION)
		ft_motion(info);
	else if (info->ev.event.type == SDL_MOUSEBUTTONDOWN &&
		info->flags.shoot == 0)
	{
		if (info->ev.event.button.button == SDL_BUTTON_LEFT)
			info->flags.shoot = 1;
	}
	else if (info->ev.event.type == SDL_MOUSEBUTTONUP)
	{
		if (info->ev.event.button.button == SDL_BUTTON_LEFT &&
			info->gun != 1 && info->gun != 2 && info->gun != 6)
			info->flags.shoot = 0;
	}
	else if (info->ev.event.key.keysym.sym == SDLK_TAB &&
		info->ev.event.type == SDL_KEYDOWN)
		ft_hide_mouse(info);
}
