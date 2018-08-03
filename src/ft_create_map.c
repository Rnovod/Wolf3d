/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:21:04 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/16 17:21:05 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/wolf3d.h"

static	char			*ft_read(t_info *info, int fd)
{
	ssize_t		ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	char		*str;

	if (!(str = ft_strnew(0)))
		ft_error(info, ENOMEM);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = str;
		buff[ret] = '\0';
		if (!(str = ft_strjoin(tmp, buff)))
		{
			free(tmp);
			ft_error(info, ENOMEM);
		}
		free(tmp);
	}
	if (ret < 0)
	{
		free(str);
		ft_error(info, -1);
	}
	return (str);
}

static	int				ft_open(t_info *info, char *namefile)
{
	int			fd;

	fd = open(namefile, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl(namefile);
		ft_error(info, -1);
	}
	return (fd);
}

static	void			ft_valid(t_info *info, char *str)
{
	int		i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\n')
	{
		free(str);
		ft_putendl("Extra space or newline.");
		ft_error(info, -8);
	}
	while (str[i] != '\0')
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') ||
			(str[i] == ' ' && str[i + 1] == ' ' && str[i + 2] == ' ') ||
			(i - 1 > 0 && str[i] == '\n' && str[i - 1] == ' '))
		{
			ft_putendl("Extra space or newline.");
			free(str);
			ft_error(info, -8);
		}
		i++;
	}
}

char					**ft_create_map(t_info *info, char *namefile)
{
	char		*str;
	int			fd;
	char		**map;

	fd = ft_open(info, namefile);
	str = ft_read(info, fd);
	if (close(fd) < 0)
	{
		free(str);
		ft_error(info, -1);
	}
	map = ft_strsplit(str, '\n');
	ft_valid(info, str);
	free(str);
	if (!map)
		ft_error(info, ENOMEM);
	return (map);
}
