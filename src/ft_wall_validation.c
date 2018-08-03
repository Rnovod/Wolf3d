/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:46:09 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/27 18:46:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	int		ft_check_wall(char *map)
{
	int		nbr;
	int		i;

	i = 0;
	while (map[i] != '\0' && map[i] != ' ')
		i++;
	nbr = ft_atoi(map);
	if (nbr > 18 || i > 2 || nbr < 0)
	{
		ft_putendl("Invalid wall. The wall must be in the "
		"range from 0 to 18.");
		return (-1);
	}
	return (0);
}

void			ft_wall_validation(t_info *info, char **map)
{
	int		x;
	int		y;

	x = 1;
	while (map[x] != NULL)
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (ft_check_wall(&map[x][y]) < 0)
			{
				ft_free(map);
				ft_error(info, -13);
			}
			while (map[x][y] != ' ' && map[x][y] != '\0')
				y++;
			while (map[x][y] != '\0' && map[x][y] == ' ')
				y++;
		}
		x++;
	}
}
