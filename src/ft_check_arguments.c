/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:56:39 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 15:56:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_arg_music(t_info *info, char **av, int *i)
{
	(*i)++;
	if (!(av[*i]))
		ft_error(info, -2);
	info->music_file = av[*i];
	(*i)++;
}

void					ft_check_arguments(t_info *info, int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (av[i] != NULL)
		{
			if (ft_strcmp(av[i], "-m") == 0)
				ft_arg_music(info, av, &i);
			else if (!info->map_name)
			{
				info->map_name = av[i];
				i++;
			}
			else
				ft_error(info, -11);
		}
	}
}
