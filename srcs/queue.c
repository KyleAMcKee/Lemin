/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:56:07 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/04 19:06:08 by kmckee           ###   ########.fr       */
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
    first = 0;
    last = 0;
    return (queue);
}

/*
**  Add item to queue and check whether first and last items exist
*/

void    enqueue(t_queue *queue, t_room *room)
{
    t_queue_item* new = malloc(sizeof(t_queue_item));
	new->room = room;
	new->next = 0;
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
        return (0);
    queue->first->room->visited = 1;
    temp = queue->first;
    queue->first = temp->next;
    free (temp);
}

int     queue_empty(t_queue *queue)
{
    if (queue->first)
        return (1);
    return (0);
}


