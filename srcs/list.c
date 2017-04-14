/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:24:55 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 19:24:57 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

t_list	*new_list(size_t elt_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(list->elts = malloc(elt_size * 4)))
		return (NULL);
	list->size = 4;
	list->len = 0;
	list->elt_size = elt_size;
	return (list);
}

void	double_list_size(t_list *lst)
{
	char	*new_elts;
	char	*elts;
	size_t	i;
	size_t	x;

	lst->size *= 2;
	if (!(new_elts = (char*)malloc(lst->elt_size * lst->size)))
		return ;
	elts = (char*)lst->elts;
	i = 0;
	while (i < lst->len)
	{
		x = 0;
		while (x < lst->elt_size)
		{
			new_elts[i * lst->elt_size + x] = elts[i * lst->elt_size + x];
			x++;
		}
		i++;
	}
	free(lst->elts);
	lst->elts = (void*)new_elts;
}

void	add_to_list(t_list *lst, void *elt)
{
	size_t	i;
	char	*elts;
	char	*elt_bytes;

	if (lst->size == lst->len)
		double_list_size(lst);
	if (!lst->elts)
		return ;
	i = 0;
	elts = (char*)lst->elts;
	elt_bytes = (char*)elt;
	while (i < lst->elt_size)
	{
		elts[lst->len * lst->elt_size + i] = elt_bytes[i];
		i++;
	}
	lst->len++;
}
