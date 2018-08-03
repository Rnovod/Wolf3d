/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tex_surf_from_files.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:05:21 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/19 16:05:22 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void			ft_tex_guns(t_info *info)
{
	info->tex.knife[0] = ft_create_text(info, "./img/f_g/knife1.bmp");
	info->tex.knife[1] = ft_create_text(info, "./img/f_g/knife2.bmp");
	info->tex.knife[2] = ft_create_text(info, "./img/f_g/knife3.bmp");
	info->tex.knife[3] = ft_create_text(info, "./img/f_g/knife4.bmp");
	info->tex.pistol[0] = ft_create_text(info, "./img/f_g/pistol1.bmp");
	info->tex.pistol[1] = ft_create_text(info, "./img/f_g/pistol2.bmp");
	info->tex.pistol[2] = ft_create_text(info, "./img/f_g/pistol3.bmp");
	info->tex.machine[0] = ft_create_text(info, "./img/f_g/machine1.bmp");
	info->tex.machine[1] = ft_create_text(info, "./img/f_g/machine2.bmp");
	info->tex.machine[2] = ft_create_text(info, "./img/f_g/machine3.bmp");
	info->tex.minigun[0] = ft_create_text(info, "./img/f_g/mini1.bmp");
	info->tex.minigun[1] = ft_create_text(info, "./img/f_g/mini2.bmp");
	info->tex.minigun[2] = ft_create_text(info, "./img/f_g/mini3.bmp");
	info->tex.flameth[0] = ft_create_text(info, "./img/f_g/flameth1.bmp");
	info->tex.flameth[1] = ft_create_text(info, "./img/f_g/flameth2.bmp");
	info->tex.flameth[2] = ft_create_text(info, "./img/f_g/flameth3.bmp");
	info->tex.flameth[3] = ft_create_text(info, "./img/f_g/flameth4.bmp");
	info->tex.bazuka[0] = ft_create_text(info, "./img/f_g/bbb1.bmp");
	info->tex.bazuka[1] = ft_create_text(info, "./img/f_g/bbb2.bmp");
	info->tex.bazuka[2] = ft_create_text(info, "./img/f_g/bbb3.bmp");
	info->tex.bazuka[3] = ft_create_text(info, "./img/f_g/bbb4.bmp");
}

static	void			ft_tex_face(t_info *info)
{
	info->tex.face[1] = ft_create_text(info, "./img/f_g/face_2.bmp");
	info->tex.face[0] = ft_create_text(info, "./img/f_g/face_1.bmp");
	info->tex.face[2] = ft_create_text(info, "./img/f_g/face_3.bmp");
	info->tex.face[3] = ft_create_text(info, "./img/f_g/face_4.bmp");
	info->tex.face[4] = ft_create_text(info, "./img/f_g/face_5.bmp");
	info->tex.face[5] = ft_create_text(info, "./img/f_g/face_6.bmp");
	info->tex.face[6] = ft_create_text(info, "./img/f_g/face_7.bmp");
}

static	void			ft_tex_walls(t_info *info)
{
	info->surf.w[0] = ft_create_surf(info, "./img/wall/1.bmp");
	info->surf.w[1] = ft_create_surf(info, "./img/wall/2.bmp");
	info->surf.w[2] = ft_create_surf(info, "./img/wall/3.bmp");
	info->surf.w[3] = ft_create_surf(info, "./img/wall/4.bmp");
	info->surf.w[4] = ft_create_surf(info, "./img/wall/5.bmp");
	info->surf.w[5] = ft_create_surf(info, "./img/wall/6.bmp");
	info->surf.w[6] = ft_create_surf(info, "./img/wall/7.bmp");
	info->surf.w[7] = ft_create_surf(info, "./img/wall/8.bmp");
	info->surf.w[8] = ft_create_surf(info, "./img/wall/9.bmp");
	info->surf.w[9] = ft_create_surf(info, "./img/wall/10.bmp");
	info->surf.w[10] = ft_create_surf(info, "./img/wall/11.bmp");
	info->surf.w[11] = ft_create_surf(info, "./img/wall/12.bmp");
	info->surf.w[12] = ft_create_surf(info, "./img/wall/13.bmp");
	info->surf.w[13] = ft_create_surf(info, "./img/wall/14.bmp");
	info->surf.w[14] = ft_create_surf(info, "./img/wall/15.bmp");
	info->surf.w[15] = ft_create_surf(info, "./img/wall/16.bmp");
	info->surf.w[16] = ft_create_surf(info, "./img/wall/17.bmp");
	info->surf.w[17] = ft_create_surf(info, "./img/wall/18.bmp");
}

static	void			ft_tex_floor_ceiling(t_info *info)
{
	info->surf.fl[0] = ft_create_surf(info, "./img/floor/1.bmp");
	info->surf.fl[1] = ft_create_surf(info, "./img/floor/2.bmp");
	info->surf.fl[2] = ft_create_surf(info, "./img/floor/3.bmp");
	info->surf.fl[3] = ft_create_surf(info, "./img/floor/4.bmp");
	info->surf.fl[4] = ft_create_surf(info, "./img/floor/5.bmp");
	info->surf.fl[5] = ft_create_surf(info, "./img/floor/6.bmp");
	info->surf.cei[0] = ft_create_surf(info, "./img/ceiling/1.bmp");
	info->surf.cei[1] = ft_create_surf(info, "./img/ceiling/2.bmp");
	info->surf.cei[2] = ft_create_surf(info, "./img/ceiling/3.bmp");
	info->surf.cei[3] = ft_create_surf(info, "./img/ceiling/4.bmp");
	info->surf.cei[4] = ft_create_surf(info, "./img/ceiling/5.bmp");
	info->surf.cei[5] = ft_create_surf(info, "./img/ceiling/6.bmp");
}

void					ft_create_tex_surf_from_files(t_info *info)
{
	ft_tex_guns(info);
	ft_tex_face(info);
	ft_create_tex_menu(info);
	ft_tex_walls(info);
	ft_tex_floor_ceiling(info);
	info->tex.panel = ft_create_text(info, "./img/panel.bmp");
}
