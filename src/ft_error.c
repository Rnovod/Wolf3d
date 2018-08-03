/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:20:39 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 14:20:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_error_2(int error, t_info *info)
{
	if (error == -8 || error == -9 || error == -10 || error == -13)
	{
		ft_putstr("Invalid map. lvl ");
		ft_putnbr(info->lvl);
		ft_putendl(".");
		if (error == -9)
			ft_putendl("Wrong line length");
		else if (error == -10)
			ft_putendl("Allowed characters are: space,"
				" newline and numbers(0-9)");
	}
	else if (error == -11)
		ft_putendl("Usage : wolf3d <name_map> -m <music_file.wav>");
	else if (error == -12)
		ft_putendl("Error : invalid player position");
	else if (error == -14)
		ft_putendl("Error : didn't find the audio file.");
	else
	{
		ft_putstr("Error : ");
		ft_putendl(strerror(error));
	}
}

void					ft_error(t_info *info, int error)
{
	if (error == 0)
	{
		ft_putstr("error initializing SDL: ");
		ft_putendl(SDL_GetError());
	}
	else if (error == -1)
	{
		ft_putstr("Error : ");
		ft_putendl(strerror(errno));
	}
	else if (error == -2)
	{
		ft_putendl("Usage : wolf3d <name_map> -m <music_file.wav>");
		ft_putendl("Error: didn't put music_file name");
	}
	else if (error == -6)
		ft_putendl("Error: "
		"Width and height must be greater or equal then 200.");
	else if (error == -7)
		ft_putendl("Error: "
		"The width must be less then 1800, the height - less 1200.");
	else
		ft_error_2(error, info);
	ft_exit(info, EXIT_FAILURE);
}
