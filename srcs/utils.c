/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:13:06 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:13:07 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	startswith(char *str, char *begin)
{
	size_t	i;

	i = 0;
	while (str[i] && begin[i] && str[i] == begin[i])
		i++;
	if (!begin[i])
		return (1);
	return (0);
}

char	endswith(char *str, char *end)
{
	int		i;
	int		x;

	i = 0;
	while (str[i])
		i++;
	x = 0;
	while (end[x])
		x++;
	while (i >= 0 && x >= 0 && str[i] == end[x])
	{
		if (x == 0)
			return (1);
		i--;
		x--;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strconcat(char *st1, char *st2)
{
	char	*res;
	size_t	i;
	size_t	start;

	if (!(res = malloc(sizeof(char) * (ft_strlen(st1) + ft_strlen(st2) + 1))))
		return (NULL);
	i = 0;
	while (st1[i])
	{
		res[i] = st1[i];
		i++;
	}
	start = 0;
	while (st2[start])
	{
		res[i + start] = st2[start];
		start++;
	}
	res[i + start] = '\0';
	return (res);
}
