/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:18:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/07 11:01:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	store_path(t_queue *queue, t_lemin *lemin)
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
}

t_queue		*find_path(t_lemin *lemin)
{
	t_vertices	*adj_list;
	t_queue		*queue;

	queue = init_queue(lemin);
	initialize_rooms(lemin->rooms);
	while (CURRENT->end == FALSE)
	{
		if (queue_empty(queue) == TRUE)
			return (NULL);
		adj_list = lemin->adj_list[CURRENT->room_number];
		while (adj_list)
		{
			if (find_room(lemin->rooms, adj_list->n)->visited == FALSE)
			{
				find_room(lemin->rooms, adj_list->n)->parent = CURRENT->room_number;
				find_room(lemin->rooms, adj_list->n)->distance = CURRENT->distance + 1;
				enqueue(queue, find_room(lemin->rooms, adj_list->n));
			}
			adj_list = adj_list->next;
		}
		dequeue(queue);
	}
	return (queue);
}

/*
**	Finds all clear paths from start to end and finds the best way
**	to collectively move ants
*/

void			solve(t_lemin *lemin)
{
	t_queue	*queue;

	lemin->paths = NULL;
	queue = NULL;
	queue = find_path(lemin);
	if (!queue && !lemin->paths)
		error();
	store_path(queue, lemin);
	del_queue(&queue);
	// queue = find_path(lemin);
	// if (!queue && !lemin->paths)
	// 	error();
	// // else if (!queue && lemin->paths)
	// // 	break ;
	// store_path(queue, lemin);
	// //remove rooms
	// del_queue(&queue);
	// // }
	int i;
	while(lemin->paths)
	{
		i = -1;
		while (++i < lemin->paths->len)
			ft_putstr(find_room(lemin->rooms, lemin->paths->moves[i])->name);
		ft_putchar('\n');
		lemin->paths = lemin->paths->next;
	}
}
