/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:18:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/04 17:13:05 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	This is probably useless
*/

static	int	get_num_of_start(t_room *rooms)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp->start != 1)
		tmp = tmp->next;
	return (tmp->room_number);
}

static	int	get_num_of_end(t_room *rooms)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp->end != 1)
		tmp = tmp->next;
	return (tmp->room_number);
}



int				*find_best_solution(t_lemin *lemin)
{
	int	*movements;
	int	start_n;
	int	end_n;

	start_n = get_num_of_start(lemin->rooms);
	end_n = get_num_of_end(lemin->rooms);
}
