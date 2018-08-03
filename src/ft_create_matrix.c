/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:19:09 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 17:19:13 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static		void		ft_create_2(t_info *info, char **str, int y)
{
	int			x;
	int			nbr;

	x = 0;
	while (str[x] != NULL && x < info->map[info->lvl].width)
	{
		nbr = ft_atoi(str[x]);
		info->map[info->lvl].matrix[y][x] = nbr;
		x++;
	}
}

static	void			ft_create(t_info *info, char **map)
{
	int			y;
	char		**str;

	if (!(info->map[info->lvl].matrix =
		(int**)malloc(sizeof(int*) * (info->map[info->lvl].height))))
	{
		ft_free(map);
		ft_error(info, ENOMEM);
	}
	y = 0;
	while (y < info->map[info->lvl].height)
	{
		if (!(str = ft_strsplit(map[y + 1], ' ')) ||
			!(info->map[info->lvl].matrix[y] =
				(int*)malloc(sizeof(int) * info->map[info->lvl].width)))
		{
			ft_free(map);
			ft_free(str);
			ft_error(info, ENOMEM);
		}
		ft_create_2(info, str, y);
		ft_free(str);
		y++;
	}
}

static	void			ft_valid_place(t_info *info)
{
	if (info->map[info->lvl].
		matrix[info->map[info->lvl].player_x]
		[info->map[info->lvl].player_y] != 0)
		ft_error(info, -12);
}

void					ft_create_matrix(t_info *info, char *namefile)
{
	char	**map;

	map = ft_create_map(info, namefile);
	ft_validation(info, map);
	ft_create(info, map);
	ft_validate_matrix(info);
	ft_valid_place(info);
	ft_free(map);
}
