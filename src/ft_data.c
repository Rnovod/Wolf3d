/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 20:35:45 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 20:35:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_clear_data(t_info *info)
{
	int		i;
	int		size;

	size = info->win.width * info->win.height;
	i = 0;
	if (info->img.data.arr)
	{
		while (i < size)
		{
			info->img.data.arr[i] = 0;
			i++;
		}
	}
}

void					ft_create_data(t_info *info)
{
	free(info->img.data.arr);
	if (!(info->img.data.arr =
		(int*)malloc(sizeof(int) * info->win.width * info->win.height)))
		ft_error(info, ENOMEM);
	info->img.data.s_line = info->win.width * 4;
}

void					ft_create_tex_data(t_info *info)
{
	SDL_Surface			*surface;

	if (!(surface =
		SDL_CreateRGBSurfaceFrom(info->img.data.arr,
					info->win.width, info->win.height, 32,
					info->img.data.s_line, 0, 0, 0, 0)))
		ft_error(info, 0);
	SDL_DestroyTexture(info->tex.walls);
	if (!(info->tex.walls =
		SDL_CreateTextureFromSurface(info->img.rend, surface)))
		ft_error(info, 0);
	SDL_FreeSurface(surface);
}
