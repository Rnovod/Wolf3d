/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:11:57 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 16:11:58 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

void				ft_signal(int sig)
{
	(void)sig;
	SDL_Quit();
	exit(1);
}

int					main(int ac, char **av)
{
	t_info				info;

	ft_set_default_info(&info);
	ft_check_arguments(&info, ac, av);
	ft_create_lvls(&info);
	ft_check_audio_files(&info);
	ft_create_audio(&info, info.music_file);
	ft_init_sdl(&info);
	ft_create_tex_surf_from_files(&info);
	ft_create_data(&info);
	ft_create_minimap(&info);
	ft_set_position(&info);
	signal(SIGTSTP, &ft_signal);
	ft_events(&info);
	ft_exit(&info, EXIT_SUCCESS);
}
