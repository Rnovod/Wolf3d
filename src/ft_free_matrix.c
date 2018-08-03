/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 16:55:11 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/28 16:55:12 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_free_matrix(t_info *info, int lvl)
{
	int	i;

	i = 0;
	if (info->map[lvl].matrix)
	{
		while ((info->map[lvl].matrix)[i] && i < info->map[lvl].height)
		{
			free((info->map[lvl].matrix)[i]);
			(info->map[lvl].matrix)[i] = NULL;
			i++;
		}
		free(info->map[lvl].matrix);
		info->map[lvl].matrix = NULL;
	}
}

void					ft_free_matrices(t_info *info)
{
	int		lvl;

	lvl = 0;
	while (lvl < 6)
	{
		if (info->map[lvl].matrix)
			ft_free_matrix(info, lvl);
		lvl++;
	}
}
