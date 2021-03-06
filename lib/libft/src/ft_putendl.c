/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:31:59 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/03 20:39:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/libft.h"

void	ft_putendl(char const *s)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
