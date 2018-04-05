/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:56:07 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/05 09:22:16 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**  Create queue to be used
*/

t_queue *init_queue(void)
{
	t_queue *queue;

	queue = (t_queue*)malloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

/*
**  Add item to queue and check whether first and last items exist
*/

void    enqueue(t_queue *queue, t_room *room)
{
	t_queue_item	*new;

	new = (t_queue_item *)ft_memalloc(sizeof(t_queue_item));
	new->room = room;
	new->next = NULL;
	if (!queue->first)
		queue->first = new;
	if (queue->last)
		queue->last->next = new;
	queue->last = new;
}

/*
**  Mark room as visited, remove from queue, and free
*/

void    dequeue(t_queue *queue)
{
	t_queue_item *temp;

	if (!queue->first)
		error();
	queue->first->room->visited = 1;
	temp = queue->first;
	queue->first = temp->next;
	free(temp);
	temp = NULL;
}

/*
**	Checks if queue is empty
*/

int     queue_empty(t_queue *queue)
{
	if (queue->first)
		return (FALSE);
	return (TRUE);
}

/*
**	
*/

void	del_queue(t_queue *queue)
{
	t_queue_item *temp;

	while (queue->first)
	{
    	temp = queue->first;
		queue->first = temp->next;
		free(temp);
		temp = NULL;
	}
	free(queue);
}
