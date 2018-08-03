/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_panel_and_face.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:19:43 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/20 14:19:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_put_panel(t_info *info)
{
	SDL_Rect	dest_r;

	info->tex.w_panel = info->win.width;
	info->tex.h_panel = info->win.height / 8;
	dest_r.x = 0;
	dest_r.y = info->win.height - info->tex.h_panel;
	dest_r.w = info->tex.w_panel;
	dest_r.h = info->tex.h_panel;
	SDL_RenderCopy(info->img.rend, info->tex.panel, NULL, &dest_r);
}

static	void			ft_emotion(t_info *info, SDL_Rect dest_face)
{
	if (info->flags.forward == 1)
		SDL_RenderCopy(info->img.rend, info->tex.face[4], NULL, &dest_face);
	else if (info->flags.back == 1)
		SDL_RenderCopy(info->img.rend, info->tex.face[5], NULL, &dest_face);
	else if (info->flags.turn_l == 1 || (info->ev.event.type == SDL_MOUSEMOTION
		&& info->ev.event.motion.xrel < 0 && info->flags.hide_mouse))
		SDL_RenderCopy(info->img.rend, info->tex.face[0], NULL, &dest_face);
	else if (info->flags.turn_r == 1 || (info->ev.event.type == SDL_MOUSEMOTION
		&& info->ev.event.motion.xrel > 0 && info->flags.hide_mouse))
		SDL_RenderCopy(info->img.rend, info->tex.face[2], NULL, &dest_face);
	else if (info->flags.blink_eyes > 300 && info->flags.blink_eyes <= 350)
		SDL_RenderCopy(info->img.rend, info->tex.face[6], NULL, &dest_face);
	else
		SDL_RenderCopy(info->img.rend, info->tex.face[1], NULL, &dest_face);
}

void					ft_put_face(t_info *info)
{
	SDL_Rect	dest_face;

	dest_face.x = info->win.width / 2 - (int)(info->win.width / 10 * 0.9);
	dest_face.y = info->win.height - info->tex.h_panel;
	dest_face.w = info->win.width / 10;
	dest_face.h = info->tex.h_panel - info->tex.h_panel / 14;
	if (info->flags.shoot >= 1)
		SDL_RenderCopy(info->img.rend, info->tex.face[3], NULL, &dest_face);
	else
		ft_emotion(info, dest_face);
}
