/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_random_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:04:08 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/28 16:04:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_malloc_matr(t_info *info, int height, int width)
{
	int		x;

	if (!(info->map[0].matrix =
		(int**)malloc(sizeof(int*) * height)))
		ft_error(info, ENOMEM);
	x = 0;
	while (x < height)
	{
		if (!(info->map[0].matrix[x] =
			(int*)malloc(sizeof(int) * width)))
			ft_error(info, ENOMEM);
		x++;
	}
}

static	void			ft_put_walls(t_info *info, int height, int width)
{
	int		x;
	int		y;
	int		r;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			r = rand() % 3 + 6;
			if ((rand() + x + y) % 4 <= 2)
				r = 0;
			info->map[0].matrix[x][y] = r;
			y++;
		}
		x++;
	}
}

static	void			ft_put_walls_around(t_info *info, int height, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		if (info->map[0].matrix[0][i] != 8)
			info->map[0].matrix[0][i] = 8;
		if (info->map[0].matrix[height - 1][i] != 8)
			info->map[0].matrix[height - 1][i] = 8;
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (info->map[0].matrix[i][0] != 8)
			info->map[0].matrix[i][0] = 8;
		if (info->map[0].matrix[i][width - 1] != 8)
			info->map[0].matrix[i][width - 1] = 8;
		i++;
	}
}

static	void			ft_put_player(t_info *info, int h, int w)
{
	int		x;
	int		y;

	x = h / 2 - 1;
	y = w / 2 - 1;
	info->map[0].matrix[x][y] = 0;
	info->map[0].matrix[x][y + 1] = 0;
	info->map[0].matrix[x][y - 1] = 0;
	info->map[0].matrix[x + 1][y] = 0;
	info->map[0].matrix[x - 1][y] = 0;
	info->map[0].matrix[x + 1][y - 1] = 0;
	info->map[0].matrix[x + 1][y + 1] = 0;
	info->map[0].matrix[x - 1][y + 1] = 0;
	info->map[0].matrix[x - 1][y - 1] = 0;
	info->map[0].player_x = x;
	info->map[0].player_y = y;
}

void					ft_create_random_map(t_info *info)
{
	int		height;
	int		width;

	srand(time(NULL));
	height = rand();
	width = rand();
	while (height > 100 || height < 10)
		height = rand();
	while (width > 100 || width < 10)
		width = rand();
	info->map[0].height = height;
	info->map[0].width = width;
	ft_malloc_matr(info, height, width);
	ft_put_walls(info, height, width);
	ft_put_walls_around(info, height, width);
	ft_put_player(info, height, width);
}
