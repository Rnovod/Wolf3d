/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:20:45 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 14:20:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_deystroy_tex_guns(t_info *info)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		SDL_DestroyTexture(info->tex.knife[i]);
		SDL_DestroyTexture(info->tex.pistol[i]);
		SDL_DestroyTexture(info->tex.machine[i]);
		SDL_DestroyTexture(info->tex.minigun[i]);
		SDL_DestroyTexture(info->tex.flameth[i]);
		SDL_DestroyTexture(info->tex.bazuka[i]);
		i++;
	}
	SDL_DestroyTexture(info->tex.knife[i]);
	SDL_DestroyTexture(info->tex.flameth[i]);
	SDL_DestroyTexture(info->tex.bazuka[i]);
}

static	void			ft_deystroy_tex_menu(t_info *info)
{
	int		i;

	SDL_DestroyTexture(info->tex.menu[0]);
	SDL_DestroyTexture(info->tex.menu[1]);
	i = 0;
	while (i < 4)
	{
		SDL_DestroyTexture(info->tex.choose[i]);
		SDL_DestroyTexture(info->tex.no_choose[i]);
		SDL_DestroyTexture(info->tex.ch_lvl[i]);
		SDL_DestroyTexture(info->tex.no_ch_lvl[i]);
		SDL_DestroyTexture(info->tex.face[i]);
		i++;
	}
	while (i < 7)
	{
		SDL_DestroyTexture(info->tex.ch_lvl[i]);
		SDL_DestroyTexture(info->tex.no_ch_lvl[i]);
		i++;
	}
}

static	void			ft_free_surfaces(t_info *info)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		SDL_FreeSurface(info->surf.fl[i]);
		SDL_FreeSurface(info->surf.cei[i]);
		SDL_FreeSurface(info->surf.w[i]);
		i++;
	}
	while (i < 18)
	{
		SDL_FreeSurface(info->surf.w[i]);
		i++;
	}
}

static	void			ft_free_everyth(t_info *info)
{
	ft_deystroy_tex_guns(info);
	ft_deystroy_tex_menu(info);
	ft_free_surfaces(info);
	ft_free_matrices(info);
	if (info->img.data.arr)
		free(info->img.data.arr);
	if (info->img.m_map.arr)
		free(info->img.m_map.arr);
	SDL_CloseAudio();
	SDL_FreeWAV(info->a.audio_buf);
	SDL_DestroyTexture(info->tex.minimap);
	SDL_DestroyTexture(info->tex.walls);
	SDL_DestroyTexture(info->tex.panel);
	SDL_DestroyRenderer(info->img.rend);
	SDL_DestroyWindow(info->win.win);
	SDL_ClearError();
	atexit(SDL_Quit);
}

void					ft_exit(t_info *info, int status)
{
	ft_free_everyth(info);
	exit(status);
}
