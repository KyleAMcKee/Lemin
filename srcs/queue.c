/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:56:07 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/09 17:18:47 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**  Create queue to be used
*/

t_queue	*init_queue(t_lemin *lemin)
{
	t_queue *queue;

	queue = (t_queue*)malloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	enqueue(queue, find_room(lemin->rooms, get_num_of_start(lemin->rooms)));
	return (queue);
}

/*
**  Add item to queue and check whether first and last items exist
*/

void	enqueue(t_queue *queue, t_room *room)
{
	t_queue_item	*new;

	new = (t_queue_item *)ft_memalloc(sizeof(t_queue_item));
	new->room = room;
	new->next = NULL;
	new->room->visited = TRUE;
	if (!queue->first)
		queue->first = new;
	if (queue->last)
		queue->last->next = new;
	queue->last = new;
}

/*
**  Mark room as visited, remove from queue, and free
*/

void	dequeue(t_queue *queue)
{
	t_queue_item *temp;

	if (!queue->first)
		error();
	temp = queue->first;
	queue->first = temp->next;
	free(temp);
	temp = NULL;
}

/*
**	Checks if queue is empty
*/

int		queue_empty(t_queue *queue)
{
	if (queue)
	{
		if (queue->first)
			return (FALSE);
	}
	return (TRUE);
}

/*
**	Deletes all elements of queue
*/

void	del_queue(t_queue **queue)
{
	t_queue_item *temp;

	while ((*queue)->first)
	{
		temp = (*queue)->first;
		(*queue)->first = temp->next;
		free(temp);
		temp = NULL;
	}
	free(*queue);
	*queue = NULL;
}
