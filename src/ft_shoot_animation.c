/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shoot_animation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:04:09 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/22 17:04:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_hit_knife(t_info *info, SDL_Rect dest_r)
{
	if (info->flags.shoot > 0 && info->flags.shoot < 20)
		SDL_RenderCopy(info->img.rend, info->tex.knife[1], NULL, &dest_r);
	else if (info->flags.shoot >= 20 && info->flags.shoot < 40)
		SDL_RenderCopy(info->img.rend, info->tex.knife[2], NULL, &dest_r);
	else if (info->flags.shoot >= 40 && info->flags.shoot <= 60)
		SDL_RenderCopy(info->img.rend, info->tex.knife[3], NULL, &dest_r);
	else
	{
		SDL_RenderCopy(info->img.rend, info->tex.knife[0], NULL, &dest_r);
		info->flags.shoot = 0;
	}
}

static	void			ft_shoot_pistol_machine(t_info *info, SDL_Rect dest_r)
{
	if (info->gun == 2)
	{
		if (info->flags.shoot > 0 && info->flags.shoot < 30)
			SDL_RenderCopy(info->img.rend, info->tex.pistol[1], NULL, &dest_r);
		else if (info->flags.shoot >= 30 && info->flags.shoot <= 60)
			SDL_RenderCopy(info->img.rend, info->tex.pistol[2], NULL, &dest_r);
		else
		{
			SDL_RenderCopy(info->img.rend, info->tex.pistol[0], NULL, &dest_r);
			info->flags.shoot = 0;
		}
	}
	else
	{
		if (info->flags.shoot > 0 && info->flags.shoot < 20)
			SDL_RenderCopy(info->img.rend, info->tex.machine[1], NULL, &dest_r);
		else if (info->flags.shoot >= 20 && info->flags.shoot <= 40)
			SDL_RenderCopy(info->img.rend, info->tex.machine[2], NULL, &dest_r);
		else
		{
			SDL_RenderCopy(info->img.rend, info->tex.machine[0], NULL, &dest_r);
			info->flags.shoot = 1;
		}
	}
}

static	void			ft_shoot_minigun_flameth(t_info *info, SDL_Rect dest_r)
{
	if (info->gun == 4)
	{
		if (info->flags.shoot > 0 && info->flags.shoot < 20)
			SDL_RenderCopy(info->img.rend, info->tex.minigun[1], NULL, &dest_r);
		else if (info->flags.shoot >= 20 && info->flags.shoot <= 40)
			SDL_RenderCopy(info->img.rend, info->tex.minigun[2], NULL, &dest_r);
		else
		{
			SDL_RenderCopy(info->img.rend, info->tex.minigun[0], NULL, &dest_r);
			info->flags.shoot = 1;
		}
	}
	else
	{
		if (info->flags.shoot > 0 && info->flags.shoot < 30)
			SDL_RenderCopy(info->img.rend, info->tex.flameth[2], NULL, &dest_r);
		else if (info->flags.shoot >= 30 && info->flags.shoot <= 60)
			SDL_RenderCopy(info->img.rend, info->tex.flameth[3], NULL, &dest_r);
		else
		{
			SDL_RenderCopy(info->img.rend, info->tex.flameth[2], NULL, &dest_r);
			info->flags.shoot = 1;
		}
	}
}

static	void			ft_shoot_bazuka(t_info *info, SDL_Rect dest_r)
{
	if (info->flags.shoot > 0 && info->flags.shoot < 30)
		SDL_RenderCopy(info->img.rend, info->tex.bazuka[1], NULL, &dest_r);
	else if (info->flags.shoot >= 30 && info->flags.shoot <= 60)
		SDL_RenderCopy(info->img.rend, info->tex.bazuka[2], NULL, &dest_r);
	else if (info->flags.shoot >= 60 && info->flags.shoot <= 90)
		SDL_RenderCopy(info->img.rend, info->tex.bazuka[3], NULL, &dest_r);
	else
	{
		SDL_RenderCopy(info->img.rend, info->tex.bazuka[0], NULL, &dest_r);
		info->flags.shoot = 0;
	}
}

void					ft_shoot_animation(t_info *info, SDL_Rect dest_r)
{
	if (info->gun == 1)
		ft_hit_knife(info, dest_r);
	else if (info->gun == 2 || info->gun == 3)
		ft_shoot_pistol_machine(info, dest_r);
	else if (info->gun == 4 || info->gun == 5)
		ft_shoot_minigun_flameth(info, dest_r);
	else if (info->gun == 6)
		ft_shoot_bazuka(info, dest_r);
}
