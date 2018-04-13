/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:18:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/13 14:27:50 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			store_path(t_queue *queue, t_lemin *lemin)
{
	int	*n;
	int len;
	int	i;

	len = CURRENT->distance + 1;
	i = len;
	n = (int *)ft_memalloc(sizeof(int) * len);
	while (--i > -1)
	{
		n[i] = CURRENT->room_number;
		if (CURRENT->parent == -1)
			break ;
		CURRENT = find_room(lemin->rooms, CURRENT->parent);
	}
	add_path(&lemin->paths, new_path(&n, len));
	if (len == 2)
		return (0);
	else
		return (1);
}

t_queue		*find_path(t_lemin *lemin)
{
	t_vertices	*adj_list;
	t_queue		*queue;

	queue = init_queue(lemin);
	initialize_rooms(lemin, lemin->rooms);
	while (CURRENT->end == FALSE)
	{
		adj_list = lemin->adj_list[CURRENT->room_number];
		while (adj_list)
		{
			if (find_room(lemin->rooms, adj_list->n)->visited == FALSE)
			{
				find_room(lemin->rooms, adj_list->n)->parent =
												CURRENT->room_number;
				find_room(lemin->rooms, adj_list->n)->distance =
												CURRENT->distance + 1;
				enqueue(queue, find_room(lemin->rooms, adj_list->n));
			}
			adj_list = adj_list->next;
		}
		dequeue(queue);
		if (queue_empty(queue) == TRUE)
			return (NULL);
	}
	return (queue);
}

/*
**	Finds all clear paths from start to end and finds the best way
**	to collectively move ants
*/

void		solve(t_lemin *lemin)
{
	t_queue	*queue;

	lemin->paths = NULL;
	queue = NULL;
	while ((queue = find_path(lemin)))
	{
		if (!queue)
			error();
		if (store_path(queue, lemin) == 0)
		{
			del_queue(&queue);
			break ;
		}
		del_queue(&queue);
	}
	if (!lemin->paths)
		error();
}
