/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:18:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/05 13:48:30 by rzarate          ###   ########.fr       */
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

// void		bfs(t_lemin *lemin, t_queue *queue, int *moves, int n)
// {
// 	// ft_putstr(queue->first->room->name);
// 	if (queue->first->room->end == TRUE)
// 	{
// 		int i;

// 		i = -1;
// 		moves[n] = queue->first->room->room_number + 1;
// 		while (++i < n + 1)
// 			ft_putstr(find_room(lemin->rooms, moves[i - 1])->name);
// 		// return (n);
// 	}
// 	else if (queue_empty(queue) == TRUE)
// 		error();
// 	else
// 	{
		// if (!lemin->adj_list || !unvisited_room(lemin, queue->first->room->room_number))
		// {
		// 	ft_putstr("TEST");
		// 	moves[--n] = 0;
		// 	dequeue(queue);
		// 	bfs(lemin, queue, moves, n);
		// }
// 		// else
// 		// {
// 		moves[n] = queue->first->room->room_number + 1;
// 		while (lemin->adj_list[queue->first->room->room_number])
// 		{
// 			if (find_room(lemin->rooms, lemin->adj_list[queue->first->room->room_number]->n)->visited == FALSE)
// 				enqueue(queue, find_room(lemin->rooms, lemin->adj_list[queue->first->room->room_number]->n));
// 			lemin->adj_list[queue->first->room->room_number] = lemin->adj_list[queue->first->room->room_number]->next;
// 		}
// 		dequeue(queue);
// 		bfs(lemin, queue, moves, ++n);
// 		// }
// 	}

// }

/*
**	Finds all clear paths from start to end and finds the best way
**	to collectively move ants
*/

void			solve(t_lemin *lemin)
{
	int				ended;
	t_queue			*queue;
	int				*moves;

	moves = (int *)ft_memalloc(sizeof(int) * lemin->graph_data->rooms);
	queue = init_queue();
	// queue2 = init_queue();
	ended = FALSE;
	// t_room *tmp = lemin->rooms;
	// while (tmp)
	// {
	// 	ft_putstr(tmp->name);
	// 	tmp = tmp->next;
	// }
	// ft_putnbr(get_num_of_start(lemin->rooms));
	// ft_putstr(find_room(lemin->rooms, get_num_of_start(lemin->rooms))->name);
	// ft_putnbr(get_nth_room(lemin->rooms, get_num_of_start(lemin->rooms))->coords[1]);
	enqueue(queue, find_room(lemin->rooms, get_num_of_start(lemin->rooms)));
	queue->first->room->parent = -1;
	// 	// RECURSIVE BACKTRACKING
	// ft_putstr("\n\n\nBACKTRACKING:\n");
	// bfs(lemin, queue, moves, 0);


	ft_putstr("\n\n\nITERATIVE:\n");
	while (queue->first->room->end == FALSE)
	{
		if (queue_empty(queue) == TRUE)
			error();
		else
		{
			// ft_putstr(queue->first->room->name);
			while (lemin->adj_list[queue->first->room->room_number])
			{
				if (find_room(lemin->rooms, lemin->adj_list[queue->first->room->room_number]->n)->visited == FALSE)
				{
					find_room(lemin->rooms, lemin->adj_list[queue->first->room->room_number]->n)->parent = queue->first->room->room_number;
					enqueue(queue, find_room(lemin->rooms, lemin->adj_list[queue->first->room->room_number]->n));
				}
				lemin->adj_list[queue->first->room->room_number] = lemin->adj_list[queue->first->room->room_number]->next;
			}
			dequeue(queue);
		}
	}
	while (queue)
	{
		ft_putstr(queue->first->room->name);
		if (queue->first->room->parent == -1)
			break ;
		queue->first->room = find_room(lemin->rooms, queue->first->room->parent);
	}
	del_queue(queue);
}
