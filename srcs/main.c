/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:56:25 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/04 05:56:03 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	Test cases are in the test dir. Parsing is done, I just need to protect it
**	from some invalid input. 
**	You can test it by running ./lem-in < tests/testX.txt
**	The adjacency list is under the lemin structure. You can access is through
**	lemin->adj_list
**	The indexes of the array correspond to the room_number
**	I couldn't figure out the bfs algorithm. Apparently we need to use a queue
**	to be able to handle large tests
*/


int main(void)
{
	t_lemin	*lemin;

	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	parse_input(lemin);



	// THE FOLLOWING BLOCK OF CODE PRINTS THE MOST IMPORTANT PARSED INFO
	// printf("# ants: %d, start: %d, end: %d, # rooms: %d\n\n", lemin->graph_data->ants, lemin->graph_data->start, lemin->graph_data->end, lemin->graph_data->rooms);
	// while (lemin->rooms)
	// {
	// 	printf("number: %i, name: %s, coords: <%d, %d>, start: %i, end: %i\n", lemin->rooms->room_number, lemin->rooms->name, lemin->rooms->coords[0], lemin->rooms->coords[1], lemin->rooms->start, lemin->rooms->end);
	// 	lemin->rooms = lemin->rooms->next;
	// }
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
