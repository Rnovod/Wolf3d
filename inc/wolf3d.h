/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:17:46 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/06 17:20:19 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "./../lib/libft/inc/libft.h"
# include <time.h>
# include <math.h>
# include <errno.h>
# include <SDL2/SDL.h>
# include <signal.h>

typedef	struct			s_event
{
	SDL_Event			event;
	int					close_requested;
}						t_event;

typedef	struct			s_minimap
{
	int					*arr;
	int					s_line;
}						t_minimap;

typedef	struct			s_data
{
	int					*arr;
	int					s_line;
}						t_data;

typedef	struct			s_texture
{
	SDL_Texture			*knife[4];
	SDL_Texture			*pistol[3];
	SDL_Texture			*machine[3];
	SDL_Texture			*minigun[3];
	SDL_Texture			*flameth[4];
	SDL_Texture			*bazuka[4];
	SDL_Texture			*face[7];
	SDL_Texture			*menu[2];
	SDL_Texture			*choose[4];
	SDL_Texture			*no_choose[4];
	SDL_Texture			*ch_lvl[7];
	SDL_Texture			*no_ch_lvl[7];
	SDL_Texture			*panel;
	int					w_panel;
	int					h_panel;
	SDL_Texture			*walls;
	SDL_Texture			*minimap;
}						t_texture;

typedef	struct			s_surface
{
	SDL_Surface			*w[18];
	SDL_Surface			*fl[6];
	SDL_Surface			*cei[6];
	SDL_Surface			*minimap;
}						t_surface;

typedef	struct			s_img
{
	SDL_Renderer		*rend;
	t_data				data;
	t_minimap			m_map;
}						t_img;

typedef	struct			s_win
{
	SDL_Window			*win;
	int					height;
	int					width;
}						t_win;

typedef	struct			s_map
{
	int					**matrix;
	int					height;
	int					width;
	int					player_x;
	int					player_y;
}						t_map;

typedef	struct			s_au_ud
{
	Uint8				*buffer;
	Uint32				buffer_len;
	Uint32				loaded_len;
}						t_au_ud;

typedef	struct			s_audio
{
	SDL_AudioSpec		loadwav_spec;
	SDL_AudioSpec		openaudio_obtained_spec;
	Uint8				*audio_buf;
	Uint32				audio_len;
	int					play;
}						t_audio;

typedef	struct			s_menu
{
	char				new_game;
	char				quit;
	char				key;
	char				option;
	char				enter;
}						t_menu;

typedef	struct			s_flags
{
	int					shoot;
	char				turn_r;
	char				turn_l;
	char				go_right;
	char				go_left;
	char				forward;
	char				back;
	int					blink_eyes;
	char				hide_mouse;
	char				run;
	char				menu;
	char				game;
	char				creater;
	char				close_win;
}						t_flags;

typedef	struct			s_dir_player
{
	double				d_x;
	double				d_y;
	double				pl_x;
	double				pl_y;
	double				p_x;
	double				p_y;
}						t_dir_player;

typedef	struct			s_info
{
	t_map				map[6];
	t_event				ev;
	t_win				win;
	t_img				img;
	t_audio				a;
	t_texture			tex;
	t_surface			surf;
	t_flags				flags;
	t_dir_player		player;
	t_menu				menu;
	char				*map_name;
	char				*music_file;
	int					lvl;
	int					gun;
	int					flame;
}						t_info;

typedef	struct			s_raycast
{
	double				ray_dx;
	double				ray_dy;
	int					map_x;
	int					map_y;
	double				side_dis_x;
	double				side_dis_y;
	double				wall_dis;
	double				delta_dx;
	double				delta_dy;
	int					step_x;
	int					step_y;
	int					side;
	int					line_h;
	int					start_y;
	int					end_y;
	double				wall_x;
	int					tex_x;
	int					tex_y;
	int					y;
	int					d;
}						t_raycast;

typedef	struct			s_fl_sky
{
	double				fl_x_w;
	double				fl_y_w;
	double				dis_w;
	double				dis_player;
	int					fl_tex_x;
	int					fl_tex_y;
	double				cur_fl_x;
	double				cur_fl_y;
}						t_fl_sky;

void					ft_error(t_info *info, int error);
void					ft_exit(t_info *info, int status);
void					ft_free_matrix(t_info *info, int lvl);
void					ft_free_matrices(t_info *info);
void					ft_clear_data(t_info *info);

void					ft_set_default_info(t_info *info);
void					ft_set_null_map(t_info *info);
void					ft_set_position(t_info *info);

void					ft_check_arguments(t_info *info, int ac, char **av);
void					ft_init_sdl(t_info *info);

void					ft_create_matrix(t_info *info, char *namefile);
char					**ft_create_map(t_info *info, char *namefile);
void					ft_create_lvls(t_info *info);
void					ft_create_random_map(t_info *info);

void					ft_check_audio_files(t_info *info);
void					ft_wall_validation(t_info *info, char **map);
void					ft_validation(t_info *info, char **map);
void					ft_validate_matrix(t_info *info);
void					ft_which(int x, int y);

void					ft_put_tex_gun(t_info *info);
void					ft_put_panel(t_info *info);
void					ft_put_face(t_info *info);
void					ft_put_minimap(t_info *info);

void					ft_create_audio(t_info *info, char *file);
SDL_Surface				*ft_create_surf(t_info *info, char *file);
SDL_Texture				*ft_create_text(t_info *info, char *file);
void					ft_create_tex_data(t_info *info);
void					ft_create_tex_surf_from_files(t_info *info);
void					ft_create_tex_menu(t_info *info);
void					ft_create_data(t_info *info);
void					ft_create_walls(t_info *info);
void					ft_create_minimap(t_info *info);

void					ft_events(t_info *info);
void					ft_event_mouse(t_info *info);
void					ft_event_keyboard(t_info *info);
void					ft_event_window(t_info *info);

void					ft_turn_right(t_info *info);
void					ft_turn_left(t_info *info);
void					ft_go_forward(t_info *info);
void					ft_go_back(t_info *info);
void					ft_go_left(t_info *info);
void					ft_go_right(t_info *info);
void					ft_change_lvl(t_info *info);

void					ft_new_game(t_info *info);
void					ft_calc_des(t_info *info, SDL_Rect *dest_b);
int						ft_coloring(SDL_Surface	*surf, int tex_y, int tex_x);

void					ft_press_menu_keys(t_info *info);
void					ft_unpress_menu_keys(t_info *info);
void					ft_create_menu(t_info *info);

void					ft_shoot_animation(t_info *info, SDL_Rect dest_r);

void					ft_raycasting(t_info *info);
void					ft_find_fl_sky(t_info *info, t_raycast *t, int x);
void					ft_texturing(t_info *info, t_raycast *t, int x);

void					ft_draw_pixel(t_info *info, int x, int y, int color);

#endif
