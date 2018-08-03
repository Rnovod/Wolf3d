/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:55:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/29 14:55:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_record_minimap(t_info *info)
{
	int			i;
	int			j;
	int			pos;

	i = 0;
	while (i < info->map[info->lvl].height)
	{
		j = 0;
		while (j < info->map[info->lvl].width)
		{
			if (info->map[info->lvl].matrix[i][j] == 0)
				info->img.m_map.arr[i *
					info->map[info->lvl].width + j] = 0;
			else
				info->img.m_map.arr[i *
					info->map[info->lvl].width + j] = 0xFF0000;
			j++;
		}
		i++;
	}
	pos = (int)info->player.p_x * info->map[info->lvl].width + info->player.p_y;
	info->img.m_map.arr[pos] = 0xFFFFFF;
}

static	void			ft_clear_minimap(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->map[info->lvl].width * info->map[info->lvl].height)
	{
		info->img.m_map.arr[i] = 0;
		i++;
	}
}

static	void			ft_create_surf_map(t_info *info)
{
	if (!(info->surf.minimap =
		SDL_CreateRGBSurfaceFrom(info->img.m_map.arr,
					info->map[info->lvl].width, info->map[info->lvl].height, 32,
					info->img.m_map.s_line, 0, 0, 0, 0)))
		ft_error(info, 0);
	SDL_DestroyTexture(info->tex.minimap);
	if (!(info->tex.minimap =
		SDL_CreateTextureFromSurface(info->img.rend, info->surf.minimap)))
		ft_error(info, 0);
	SDL_FreeSurface(info->surf.minimap);
}

void					ft_put_minimap(t_info *info)
{
	SDL_Rect	dest_minimap;

	dest_minimap.x = info->win.width -
	(info->win.width / 10 + info->map[info->lvl].width);
	dest_minimap.y = 0;
	dest_minimap.w = info->win.width / 10 + info->map[info->lvl].width;
	dest_minimap.h = info->win.height / 12 + info->map[info->lvl].height;
	ft_clear_minimap(info);
	ft_record_minimap(info);
	ft_create_surf_map(info);
	SDL_RenderCopy(info->img.rend, info->tex.minimap, NULL, &dest_minimap);
}

void					ft_create_minimap(t_info *info)
{
	free(info->img.m_map.arr);
	if (!(info->img.m_map.arr = (int*)malloc(sizeof(int) *
		(info->map[info->lvl].width) * (info->map[info->lvl].height))))
		ft_error(info, ENOMEM);
	info->img.m_map.s_line = info->map[info->lvl].width * 4;
}
