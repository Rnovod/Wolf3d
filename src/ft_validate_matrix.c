/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:44:42 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/28 13:44:43 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_which(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putendl(" -> Wrong wall.");
}

static	void			ft_check_horizontal_walls(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->map[info->lvl].width)
	{
		if (info->map[info->lvl].matrix[0][i] == 0)
		{
			ft_which(0, i);
			ft_error(info, -13);
		}
		if (info->map[info->lvl].matrix
			[info->map[info->lvl].height - 1][i] == 0)
		{
			ft_which(info->map[info->lvl].height - 1, i);
			ft_error(info, -13);
		}
		i++;
	}
}

static	void			ft_check_vertical_walls(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->map[info->lvl].height)
	{
		if (info->map[info->lvl].matrix[i][0] == 0)
		{
			ft_which(i, 0);
			ft_error(info, -13);
		}
		if (info->map[info->lvl].matrix
			[i][info->map[info->lvl].width - 1] == 0)
		{
			ft_which(i, info->map[info->lvl].width - 1);
			ft_error(info, -13);
		}
		i++;
	}
}

void					ft_validate_matrix(t_info *info)
{
	ft_check_horizontal_walls(info);
	ft_check_vertical_walls(info);
}
