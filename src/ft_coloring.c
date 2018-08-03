/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:00:21 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/18 14:00:22 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

int						ft_coloring(SDL_Surface *surf, int tex_y, int tex_x)
{
	int		color;

	color = ((int*)surf->pixels)[surf->h * tex_y + tex_x];
	return (color);
}
