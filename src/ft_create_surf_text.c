/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_surf_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:39:08 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/20 18:39:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

SDL_Texture					*ft_create_text(t_info *info, char *file)
{
	SDL_Texture		*texture;
	SDL_Surface		*surface;

	if (!(surface = SDL_LoadBMP(file)))
		ft_error(info, 0);
	if (!(texture =
		SDL_CreateTextureFromSurface(info->img.rend, surface)))
		ft_error(info, 0);
	SDL_FreeSurface(surface);
	return (texture);
}

SDL_Surface					*ft_create_surf(t_info *info, char *file)
{
	SDL_Surface		*load;
	SDL_PixelFormat	fmt;
	SDL_Surface		*surface;

	fmt.BitsPerPixel = 32;
	fmt.BytesPerPixel = 4;
	fmt.palette = NULL;
	fmt.Rmask = 0;
	fmt.Gmask = 0;
	fmt.Bmask = 0;
	fmt.Amask = 0;
	if (!(load = SDL_LoadBMP(file)))
		ft_error(info, 0);
	if (!(surface = SDL_ConvertSurface(load, &fmt, 0)))
		ft_error(info, 0);
	SDL_FreeSurface(load);
	return (surface);
}
