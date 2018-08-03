/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tex_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:52:07 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/16 13:52:07 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_general_menu(t_info *info)
{
	info->tex.choose[0] = ft_create_text(info, "./img/menu/continue1.bmp");
	info->tex.no_choose[0] = ft_create_text(info, "./img/menu/continue0.bmp");
	info->tex.choose[1] = ft_create_text(info, "./img/menu/new_game1.bmp");
	info->tex.no_choose[1] = ft_create_text(info, "./img/menu/new_game0.bmp");
	info->tex.choose[2] = ft_create_text(info, "./img/menu/Controls1.bmp");
	info->tex.no_choose[2] = ft_create_text(info, "./img/menu/Controls0.bmp");
	info->tex.choose[3] = ft_create_text(info, "./img/menu/Quit1.bmp");
	info->tex.no_choose[3] = ft_create_text(info, "./img/menu/Quit0.bmp");
}

static	void			ft_choose_lvl_tex(t_info *info)
{
	info->tex.ch_lvl[0] = ft_create_text(info, "./img/menu/lvl1_1.bmp");
	info->tex.no_ch_lvl[0] = ft_create_text(info, "./img/menu/lvl0_1.bmp");
	info->tex.ch_lvl[1] = ft_create_text(info, "./img/menu/lvl1_2.bmp");
	info->tex.no_ch_lvl[1] = ft_create_text(info, "./img/menu/lvl0_2.bmp");
	info->tex.ch_lvl[2] = ft_create_text(info, "./img/menu/lvl1_3.bmp");
	info->tex.no_ch_lvl[2] = ft_create_text(info, "./img/menu/lvl0_3.bmp");
	info->tex.ch_lvl[3] = ft_create_text(info, "./img/menu/lvl1_4.bmp");
	info->tex.no_ch_lvl[3] = ft_create_text(info, "./img/menu/lvl0_4.bmp");
	info->tex.ch_lvl[4] = ft_create_text(info, "./img/menu/lvl1_5.bmp");
	info->tex.no_ch_lvl[4] = ft_create_text(info, "./img/menu/lvl0_5.bmp");
	info->tex.ch_lvl[5] = ft_create_text(info, "./img/menu/lvl1_6.bmp");
	info->tex.no_ch_lvl[5] = ft_create_text(info, "./img/menu/lvl0_6.bmp");
	info->tex.ch_lvl[6] = ft_create_text(info, "./img/menu/random1.bmp");
	info->tex.no_ch_lvl[6] = ft_create_text(info, "./img/menu/random0.bmp");
}

void					ft_create_tex_menu(t_info *info)
{
	info->tex.menu[0] = ft_create_text(info, "./img/menu/menu.bmp");
	info->tex.menu[1] = ft_create_text(info, "./img/menu/Controls.bmp");
	ft_general_menu(info);
	ft_choose_lvl_tex(info);
}
