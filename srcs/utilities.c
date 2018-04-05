/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:03:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/05 09:18:24 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

/*
**	This function is only called when ## is found and it determines
**	whether start or end will be inputted next
**	if none of these is found, input is invalid
*/

int		get_start_end(char *line, t_lemin *lemin)
{
	if (ft_strequ(&line[2], "start"))
	{
		if (lemin->graph_data->start == 1)
			error();
		lemin->graph_data->start = 1;
		return (1);
	}
	else if (ft_strequ(&line[2], "end"))
	{
		if (lemin->graph_data->end == 1)
			error();
		lemin->graph_data->end = 1;
		return (2);
	}
	else
	{
		error();
		return (0);
	}
}

/*
**	Finds and return the room with a specific
**	room number
*/

t_room	*find_room(t_room *rooms, int i)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp && tmp->room_number != i)
		tmp = tmp->next;
	return (tmp);
}

/*
**	Checks if there's no non-digit characters
*/

void	only_digits(char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		(!ft_isdigit(s[i])) ? error() : 0;
}

/*
**	Frees all memory allocated by lemin
*/

void	finalize_lemin(t_lemin *lemin)
{
	del_vertices(lemin->adj_list);
	free(lemin->adj_list);
	del_rooms(&lemin->rooms);
	free(lemin->rooms);
	free(lemin->graph_data);
	free(lemin);
}
