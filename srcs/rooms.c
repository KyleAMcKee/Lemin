/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:52:21 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/05 09:19:52 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*new_room(char *name, int start_end, int coords[2], int room_number)
{
	t_room	*room;

	room = (t_room *)ft_memalloc(sizeof(t_room));
	if (!room)
		return (NULL);
	room->name = name;
	room->coords[0] = coords[0];
	room->coords[1] = coords[1];
	room->room_number = room_number;
	if (start_end == 1)
		room->start = 1;
	if (start_end == 2)
		room->end = 1;
	room->next = NULL;
	return (room);
}

void	add_room(t_room **rooms, t_room *new_room)
{
	t_room	*tmp;

	if (rooms && *rooms && new_room)
	{
		tmp = *rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_room;
	}
	else if (new_room && (!rooms || !(*rooms)))
		*rooms = new_room;
}

void	delone_room(t_room **rooms)
{
	t_room	*tmp;

	if (rooms && *rooms)
	{
		tmp = *rooms;
		*rooms = (*rooms)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	del_rooms(t_room **rooms)
{
	if (rooms)
	{
		while (*rooms)
			delone_room(rooms);
	}
	rooms = NULL;
}
