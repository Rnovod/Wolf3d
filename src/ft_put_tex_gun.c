/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tex_gun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 12:16:14 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/20 12:16:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	SDL_Texture			*ft_choose_gun(t_info *info)
{
	if (info->gun == 1)
		return (info->tex.knife[0]);
	if (info->gun == 2)
		return (info->tex.pistol[0]);
	if (info->gun == 3)
		return (info->tex.machine[0]);
	if (info->gun == 4)
		return (info->tex.minigun[0]);
	if (info->gun == 5)
		return (info->tex.flameth[0]);
	if (info->gun == 6)
		return (info->tex.bazuka[0]);
	return (NULL);
}

void						ft_put_tex_gun(t_info *info)
{
	SDL_Rect	dest_r;
	int			size_w;
	int			size_h;

	size_w = info->win.width / 5;
	size_h = info->win.height / 4;
	dest_r.x = info->win.width / 2 - size_w / 2;
	dest_r.y = info->win.height - size_h - info->tex.h_panel;
	dest_r.w = size_w;
	dest_r.h = size_h;
	if (info->flags.shoot != 0)
		ft_shoot_animation(info, dest_r);
	else if (info->gun == 5 && info->flags.shoot == 0)
	{
		if (info->flame > 0 && info->flame <= 50)
			SDL_RenderCopy(info->img.rend, info->tex.flameth[0], NULL, &dest_r);
		else
			SDL_RenderCopy(info->img.rend, info->tex.flameth[1], NULL, &dest_r);
	}
	else
		SDL_RenderCopy(info->img.rend, ft_choose_gun(info), NULL, &dest_r);
}
