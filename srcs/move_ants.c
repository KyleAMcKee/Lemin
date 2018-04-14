/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:28:08 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/14 10:38:50 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_move(t_room *current, int *first)
{
	if (*first == 1)
		write(1, " ", 1);
	write(1, "L", 1);
	ft_putstr(ft_itoa(current->ant_id));
	write(1, "-", 1);
	ft_putstr(current->name);
	*first = 1;
}

void	one_pipe(t_room *current, t_room *previous, int *first)
{
	static int ant;

	current->ants = ++ant;
	current->ant_id = current->ants;
	previous->ants--;
	print_move(current, first);
}

void	multi_pipes(t_room *current, t_room *previous, int *first)
{
	static int ant;

	if (current->end == 1)
	{
		current->ants++;
		current->ant_id = current->ants;
		previous->ants = 0;
		previous->ant_id = 0;
	}
	else if (previous->start == 1)
	{
		current->ants++;
		current->ant_id = ++ant;
		previous->ants--;
	}
	else
	{
		current->ants = 1;
		previous->ants = 0;
		current->ant_id = previous->ant_id;
	}
	print_move(current, first);
}

void	move_ants(t_room *rooms, t_path *paths, t_graph *graph)
{
	int		i;
	int		first;
	t_room	*current;
	t_room	*previous;

	first = 0;
	while (paths)
	{
		i = paths->len - 1;
		while (i > 0)
		{
			current = find_room(rooms, paths->moves[i]);
			previous = find_room(rooms, paths->moves[i - 1]);
			if (current->end == 1 && previous->start == 1 && previous->ants)
				one_pipe(current, previous, &first);
			else if (previous->ants)
			{
				multi_pipes(current, previous, &first);
				if (current->ants == graph->ants && current->end == 1)
					return ;
			}
			i--;
		}
		paths = paths->next;
	}
}

void	manage_ants(t_lemin *lemin)
{
	int		num_paths;
	int		lcm;
	t_room	*end_room;

	num_paths = number_of_paths(lemin->paths);
	end_room = find_room(lemin->rooms,
			lemin->paths->moves[lemin->paths->len - 1]);
	lcm = least_common_multiple(lemin->paths);
	while (end_room->ants < lemin->graph_data->ants)
	{
		while (lcm > lemin->graph_data->ants)
		{
			if (num_paths == 1)
				break ;
			free_last(lemin->paths);
			num_paths = number_of_paths(lemin->paths);
			lcm = least_common_multiple(lemin->paths);
		}
		move_ants(lemin->rooms, lemin->paths, lemin->graph_data);
		write(1, "\n", 1);
	}
}
