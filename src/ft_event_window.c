/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:01:56 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/17 18:01:57 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_event_window(t_info *info)
{
	if (info->ev.event.type == SDL_WINDOWEVENT)
	{
		if (info->ev.event.window.event == SDL_WINDOWEVENT_HIDDEN)
		{
			SDL_PauseAudio(1);
			info->flags.close_win = 1;
		}
		else if (info->ev.event.window.event == SDL_WINDOWEVENT_SHOWN)
		{
			SDL_PauseAudio(0);
			info->flags.close_win = 0;
		}
		else if (info->ev.event.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			SDL_GetWindowSize(info->win.win,
				&info->win.width, &info->win.height);
			ft_create_data(info);
		}
	}
}
