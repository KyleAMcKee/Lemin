/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:07:34 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/05 09:17:09 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_vertices	*new_vertice(int n)
{
	t_vertices	*vertice;

	vertice = (t_vertices *)ft_memalloc(sizeof(t_vertices));
	vertice->n = n;
	vertice->next = NULL;
	return (vertice);
}

void		add_vertice(t_vertices **adj_list, t_vertices *new_vertice)
{
	if (adj_list && *adj_list && new_vertice)
	{
		new_vertice->next = *adj_list;
		*adj_list = new_vertice;
	}
	else if (new_vertice && (!adj_list || !(*adj_list)))
		*adj_list = new_vertice;
}

void		delone_vertice(t_vertices **adj_list)
{
	t_vertices	*tmp;
	
	if (adj_list && *adj_list)
	{
		tmp = *adj_list;
		*adj_list = (*adj_list)->next;
		free(tmp);
		tmp = NULL;
	}
}

void		del_vertices(t_vertices **adj_list)
{
	if (adj_list)
	{
		while (*adj_list)
			delone_vertice(adj_list);
	}
	adj_list = NULL;
}
