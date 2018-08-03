/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_audio.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:32:11 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/17 18:32:11 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	void				ft_my_open_au(void *userdata,
								Uint8 *stream, int len)
{
	t_au_ud			*sdata;
	Uint32			new_len;

	sdata = (t_au_ud*)userdata;
	if (len > 0 && sdata && sdata->buffer)
	{
		new_len = sdata->loaded_len + len;
		if (new_len > sdata->buffer_len)
		{
			len = sdata->buffer_len - sdata->loaded_len;
			new_len = sdata->buffer_len;
		}
		SDL_memcpy(stream, sdata->buffer + sdata->loaded_len, len);
		sdata->loaded_len = new_len;
	}
	if (sdata->loaded_len >= sdata->buffer_len)
		sdata->loaded_len = 0;
}

static	void				ft_my_load_wav(void *userdata,
								Uint8 *stream, int len)
{
	t_au_ud				*sdata;
	Uint32				new_len;

	sdata = (t_au_ud*)userdata;
	if (len > 0 && sdata && sdata->buffer)
	{
		new_len = sdata->loaded_len + len;
		if (new_len > sdata->buffer_len)
		{
			len = sdata->buffer_len - sdata->loaded_len;
			new_len = sdata->buffer_len;
		}
		SDL_memcpy(stream, sdata->buffer + sdata->loaded_len, len);
		sdata->loaded_len = new_len;
	}
	if (sdata->loaded_len >= sdata->buffer_len)
		sdata->loaded_len = 0;
}

void						ft_create_audio(t_info *info, char *file)
{
	static t_au_ud		open_au_ud;
	static t_au_ud		load_wav_ud;

	SDL_FreeWAV(info->a.audio_buf);
	SDL_CloseAudio();
	info->a.audio_buf = NULL;
	open_au_ud.loaded_len = 0;
	load_wav_ud.loaded_len = 0;
	info->a.loadwav_spec.callback = ft_my_load_wav;
	info->a.loadwav_spec.userdata = (void*)&load_wav_ud;
	if (SDL_LoadWAV(file, &info->a.loadwav_spec,
		&info->a.audio_buf, &info->a.audio_len) == NULL)
		ft_error(info, 0);
	load_wav_ud.buffer = info->a.audio_buf;
	load_wav_ud.buffer_len = info->a.audio_len;
	info->a.loadwav_spec.callback = ft_my_open_au;
	info->a.loadwav_spec.userdata = (void*)&open_au_ud;
	open_au_ud.buffer = info->a.audio_buf;
	open_au_ud.buffer_len = info->a.audio_len;
	if (SDL_OpenAudio(&info->a.loadwav_spec,
		&info->a.openaudio_obtained_spec) < 0)
		ft_error(info, 0);
	SDL_PauseAudio(0);
}
