/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:56:25 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/04 00:32:03 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// void	graph_init(t_graph *graph)
// {
// 	graph->start = 0;
// 	graph->end = 0;
// 	graph->ants = 0;
// }

int main(void)
{
	t_lemin	*lemin;

	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	//rooms = (t_room**)malloc(sizeof(t_room*));
	//room_init(rooms, graph);
	// graph_init(graph);
	parse_input(lemin);
	printf("# ants: %d, start: %d, end: %d, # rooms: %d\n\n", lemin->graph_data->ants, lemin->graph_data->start, lemin->graph_data->end, lemin->graph_data->rooms);
	while (lemin->rooms)
	{
		printf("number: %i, name: %s, coords: <%d, %d>, start: %i, end: %i\n", lemin->rooms->room_number, lemin->rooms->name, lemin->rooms->coords[0], lemin->rooms->coords[1], lemin->rooms->start, lemin->rooms->end);
		lemin->rooms = lemin->rooms->next;
	}
	int i = lemin->graph_data->rooms;
	while (--i > -1)
	{
		printf("Connectios for room #: %d ---\n", i);
		while (lemin->adj_list[i])
		{
			printf("%d\n", lemin->adj_list[i]->n);
			lemin->adj_list[i] = lemin->adj_list[i]->next;
		}
	}
	return (0);
}
