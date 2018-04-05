/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:18:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/05 16:15:54 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	This is probably useless
*/

// static	int	unvisited_room(t_lemin	*lemin, int room_number)
// {
// 	t_vertices	*tmp;

// 	tmp = lemin->adj_list[room_number];
// 	while (tmp)
// 	{
// 		if (find_room(lemin->rooms, tmp->n)->visited == 0)
// 			return (TRUE);
// 	}
// 	return (FALSE);
// }

static	int	get_num_of_start(t_room *rooms)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp->start == FALSE)
		tmp = tmp->next;
	return (tmp->room_number);
}

void	store_path(t_queue *queue, t_lemin *lemin)
{
	add_path()
}

/*
**	Finds all clear paths from start to end and finds the best way
**	to collectively move ants
*/

void			solve(t_lemin *lemin)
{
	t_queue			*queue;
	int				*moves;

	lemin->paths = (t_path *)ft_memalloc(sizeof(t_path));
	moves = (int *)ft_memalloc(sizeof(int) * lemin->graph_data->rooms);
	queue = init_queue();
	enqueue(queue, find_room(lemin->rooms, get_num_of_start(lemin->rooms)));
	CURRENT->parent = -1;
	while (CURRENT->end == FALSE)
	{
		if (queue_empty(queue) == TRUE)
			error();
		else
		{
			// ft_putstr(queue->first->room->name);
			while (lemin->adj_list[CURRENT->room_number])
			{
				if (find_room(lemin->rooms, lemin->adj_list[CURRENT->room_number]->n)->visited == FALSE)
				{
					find_room(lemin->rooms, lemin->adj_list[CURRENT->room_number]->n)->parent = CURRENT->room_number;
					find_room(lemin->rooms, lemin->adj_list[CURRENT->room_number]->n)->distance = CURRENT->distance + 1;
					enqueue(queue, find_room(lemin->rooms, lemin->adj_list[CURRENT->room_number]->n));
				}
				lemin->adj_list[CURRENT->room_number] = lemin->adj_list[CURRENT->room_number]->next;
			}
			dequeue(queue);
		}
	}
	store_path(queue, lemin);
	// while (queue)
	// {
	// 	ft_putstr(CURRENT->name);
	// 	if (CURRENT->parent == -1)
	// 		break ;
	// 	CURRENT = find_room(lemin->rooms, CURRENT->parent);
	// }
	del_queue(queue);
}
