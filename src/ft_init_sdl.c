/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:56:24 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 15:56:29 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_init_sdl(t_info *info)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_error(info, 0);
	if (!(info->win.win =
		SDL_CreateWindow("LET THE GAME BEGIN", 500, 500,
						info->win.width, info->win.height,
						SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE |
						SDL_WINDOW_MOUSE_FOCUS)))
		ft_error(info, 0);
	if (!(info->img.rend = SDL_CreateRenderer(info->win.win, -1,
											SDL_RENDERER_ACCELERATED)))
		ft_error(info, 0);
}
