/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lvls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:00:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/17 14:00:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void					ft_create_lvls(t_info *info)
{
	if (info->map_name)
		ft_create_matrix(info, info->map_name);
	else
		ft_create_random_map(info);
	info->lvl = 1;
	ft_create_matrix(info, "./map/lvl_1");
	info->lvl = 2;
	ft_create_matrix(info, "./map/lvl_2");
	info->lvl = 3;
	ft_create_matrix(info, "./map/lvl_3");
	info->lvl = 4;
	ft_create_matrix(info, "./map/lvl_4");
	info->lvl = 5;
	ft_create_matrix(info, "./map/lvl_5");
	info->lvl = 0;
}
