/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_lvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:16:49 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/29 22:16:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_change(t_info *info)
{
	if (info->ev.event.key.keysym.sym == SDLK_KP_1)
		info->lvl = 0;
	else if (info->ev.event.key.keysym.sym == SDLK_KP_2)
		info->lvl = 1;
	else if (info->ev.event.key.keysym.sym == SDLK_KP_3)
		info->lvl = 2;
	else if (info->ev.event.key.keysym.sym == SDLK_KP_4)
		info->lvl = 3;
	else if (info->ev.event.key.keysym.sym == SDLK_KP_5)
		info->lvl = 4;
	else if (info->ev.event.key.keysym.sym == SDLK_KP_6)
		info->lvl = 5;
}

void					ft_change_lvl(t_info *info)
{
	int		lvl;

	lvl = info->lvl;
	if (info->ev.event.key.keysym.sym >= SDLK_KP_1 &&
			info->ev.event.key.keysym.sym <= SDLK_KP_6)
		ft_change(info);
	else if (!info->map_name && info->ev.event.key.keysym.sym == SDLK_KP_0 &&
		info->lvl == 0)
	{
		ft_free_matrix(info, 0);
		ft_create_random_map(info);
	}
	if (info->lvl != lvl || (info->lvl == 0 &&
		info->ev.event.key.keysym.sym == SDLK_KP_0 && !info->map_name))
	{
		ft_create_minimap(info);
		ft_set_position(info);
	}
}
