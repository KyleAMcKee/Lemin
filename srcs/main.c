/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:56:25 by kmckee            #+#    #+#             */
/*   Updated: 2018/03/31 20:13:37 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

void	room_init(t_room *room, t_graph *graph)
{
	static int room_num;
	
	room->room_number = room_num++;
	room->start = 0;
	room->end = 0;
	room->visited = 0;
	room->next = NULL;
	graph->rooms = room->room_number + 1;
}

void	graph_init(t_graph *graph)
{
	graph->start = 0;
	graph->end = 0;
	graph->ants = 0;
}

int main(void)
{
	t_graph	*graph;
	t_room **rooms;

	//rooms = (t_room**)malloc(sizeof(t_room*));
	graph = (t_graph*)malloc(sizeof(t_graph));
	//room_init(rooms, graph);
	graph_init(graph);
	rooms = parse_input(graph);
	while (*rooms)
	{
		printf("number: %i, start: %i, end: %i, name: %s\n", (*rooms)->room_number, (*rooms)->start, (*rooms)->end, (*rooms)->name);
		*rooms = (*rooms)->next;
	}
	printf("graph: rooms = %i\n", graph->rooms);
}
