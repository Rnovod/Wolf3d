/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:58:49 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/18 18:58:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_draw_pixel(t_info *info, int x, int y, int color)
{
	int			width;

	width = info->img.data.s_line / 4;
	if (x >= 0 && y >= 0 && x < info->win.width && y < info->win.height)
		info->img.data.arr[x + y * width] = color;
}
