/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_audio_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:08:23 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/28 14:08:23 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_check_input_music_file(t_info *info)
{
	int		fd;

	if ((fd = open(info->music_file, O_RDONLY)) < 0)
	{
		ft_putendl(info->music_file);
		ft_error(info, -14);
	}
	if (close(fd) < 0)
		ft_error(info, -1);
}

void					ft_check_audio_files(t_info *info)
{
	int		fd;

	if ((fd = open("./music/1.wav", O_RDONLY)) < 0)
	{
		ft_putendl("music/1.wav");
		ft_error(info, -14);
	}
	if (close(fd) < 0)
		ft_error(info, -1);
	if ((fd = open("./music/2.wav", O_RDONLY)) < 0)
	{
		ft_putendl("music/2.wav");
		ft_error(info, -14);
	}
	if (close(fd) < 0)
		ft_error(info, -1);
	if (info->music_file == NULL)
		info->music_file = "./music/1.wav";
	else
		ft_check_input_music_file(info);
}
