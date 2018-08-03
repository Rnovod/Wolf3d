/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:10:51 by rnovodra          #+#    #+#             */
/*   Updated: 2018/01/11 13:32:55 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

static t_list	*ft_check_fd(t_list *begin, const int fd)
{
	t_list *tmp;

	tmp = begin;
	if (tmp)
	{
		while (tmp->next != NULL && (size_t)fd != tmp->content_size)
			tmp = tmp->next;
		if ((size_t)fd != tmp->content_size)
		{
			tmp->next = ft_lstnew("", 1);
			tmp->next->content_size = (size_t)fd;
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = ft_lstnew("", 1);
		tmp->content_size = (size_t)fd;
	}
	return (tmp);
}

static int		ft_read(const int fd, char *buff, t_list *p)
{
	ssize_t	ret;
	void	*tmp;

	while (ft_strchr((char*)p->content, '\n') == NULL &&
		(ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = p->content;
		if (!(p->content = (void*)ft_strjoin((char*)tmp, buff)))
			return (-1);
		free(tmp);
	}
	free(buff);
	return (0);
}

static int		ft_del(t_list *p, size_t len)
{
	char	*tmp;

	tmp = (char*)p->content;
	if (tmp[len] == '\n')
		len++;
	if (!(p->content = (void*)ft_strsub((char*)p->content,
		(unsigned int)len, ft_strlen(&((char*)p->content)[len]))))
		return (-1);
	free(tmp);
	return (0);
}

static int		ft_add_line(char **line, t_list *p)
{
	size_t len;

	if (ft_strlen(p->content) == 0)
		return (0);
	len = ft_strclen((char*)p->content, '\n');
	if (!(*line = (char*)malloc(sizeof(char) * len + 1)))
		return (-1);
	ft_memcpy(*line, (char *)p->content, len);
	(*line)[len] = '\0';
	if (ft_del(p, len) == -1)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*begin;
	t_list			*p;
	char			*buff;
	int				x;

	if (BUFF_SIZE < 1 || !(buff = ft_strnew(BUFF_SIZE)) || fd < 0
			|| line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (!begin)
		if (!(begin = ft_check_fd(begin, fd)))
			return (-1);
	p = begin;
	if ((int)p->content_size != fd && (!(p = ft_check_fd(begin, fd))))
		return (-1);
	if (ft_read(fd, buff, p) == -1)
		return (-1);
	x = ft_add_line(line, p);
	if (x == 0)
		return (0);
	return (x > 0 ? 1 : -1);
}
