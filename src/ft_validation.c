/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:23:13 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 17:23:15 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_check_pos(t_info *info, char **map)
{
	int		len;
	int		x;
	int		y;
	int		i;

	i = 0;
	len = ft_count_words(map[0], ' ');
	if (len != 2)
		ft_error(info, -12);
	x = ft_atoi(map[0]);
	while (map[0][i] != '\0' && map[0][i] != ' ')
		i++;
	y = ft_atoi(&map[0][i]);
	if (y >= info->map[info->lvl].width || x >= info->map[info->lvl].height
		|| x <= 0 || y <= 0)
	{
		ft_putstr("In ");
		ft_putnbr(info->lvl);
		ft_putendl(" lvl");
		ft_error(info, -12);
	}
	info->map[info->lvl].player_x = x;
	info->map[info->lvl].player_y = y;
}

static	void			ft_check_length(t_info *info, char **map)
{
	int		i;
	int		len;

	i = 1;
	if (!map || !(*map))
	{
		ft_free(map);
		ft_error(info, -8);
	}
	len = ft_count_words(map[i], ' ');
	if (len == 0)
		ft_error(info, -9);
	while (map[i] != NULL)
	{
		if (len != ft_count_words(map[i], ' '))
		{
			ft_free(map);
			ft_error(info, -9);
		}
		i++;
	}
	info->map[info->lvl].width = len;
	info->map[info->lvl].height = i - 1;
}

static	void			ft_check_char(t_info *info, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != ' ' && map[i][j] != '\n' &&
				(map[i][j] < '0' || map[i][j] > '9'))
			{
				ft_putstr("In the lvl '");
				ft_putnbr(info->lvl);
				ft_putstr("' is wrong character - '");
				ft_putchar(map[i][j]);
				ft_putendl("'");
				ft_error(info, -10);
			}
			j++;
		}
		i++;
	}
}

void					ft_validation(t_info *info, char **map)
{
	ft_check_length(info, map);
	ft_check_pos(info, map);
	ft_wall_validation(info, map);
	ft_check_char(info, map);
}
