/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 04:18:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/09 12:36:48 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	store_path(t_queue *queue, t_lemin *lemin)
{
	int	*n;
	int len;
	int	i;

	len = CURRENT->distance + 1;
	i = len;
	n = (int *)ft_memalloc(sizeof(int) * len);
	while (--i > -1)
	{
		n[i] = CURRENT->room_number;
		if (CURRENT->parent == -1)
			break ;
		CURRENT = find_room(lemin->rooms, CURRENT->parent);
	}
	add_path(&lemin->paths, new_path(&n, len));
}

t_queue		*find_path(t_lemin *lemin)
{
	t_vertices	*adj_list;
	t_queue		*queue;

	queue = init_queue(lemin);
	initialize_rooms(lemin->rooms);
	while (CURRENT->end == FALSE)
	{
		if (queue_empty(queue) == TRUE)
			return (NULL);
		adj_list = lemin->adj_list[CURRENT->room_number];
		while (adj_list)
		{
			if (find_room(lemin->rooms, adj_list->n)->visited == FALSE)
			{
				find_room(lemin->rooms, adj_list->n)->parent = CURRENT->room_number;
				find_room(lemin->rooms, adj_list->n)->distance = CURRENT->distance + 1;
				enqueue(queue, find_room(lemin->rooms, adj_list->n));
			}
			adj_list = adj_list->next;
		}
		dequeue(queue);
	}
	return (queue);
}

void	remove_rooms(t_lemin *lemin)
{
	t_path			*paths;
	t_vertices		*adj_list;
	int				current;
	int				next;
	int				i;

	i = -1;
	paths = lemin->paths;
	while (paths->next)
		paths = paths->next;
	while (++i < paths->len - 1)
	{
		current = paths->moves[i];
		next = paths->moves[i + 1];
		
		adj_list = lemin->adj_list[current];
		while (adj_list->n != next)
			adj_list = adj_list->next;
		delone_vertice(&adj_list);

		adj_list =lemin->adj_list[next];
		while (adj_list->n != current)
			adj_list = adj_list->next;
		delone_vertice(&adj_list);
	}
}

void	print_adj(t_vertices **adj_list, int n)
{
	t_vertices *tmp;
	int i;

	i = -1;
	while (++i < n)
	{
		tmp = adj_list[i];
		ft_putstr("-TEST1-");
		ft_putstr("Room #: ");
		ft_putnbr(i);
		ft_putstr(" - ");
		while (tmp)
		{
			ft_putstr("-TEST2-");
			ft_putnbr(tmp->n);
			ft_putchar('-');
			tmp = tmp ->next;
		}
		ft_putstr("-TEST3-");
		ft_putchar('\n');
	}
}

/*
**	Finds all clear paths from start to end and finds the best way
**	to collectively move ants
*/

void	         		solve(t_lemin *lemin)
{
	t_queue	*queue;

	lemin->paths = NULL;
	queue = NULL;
	queue = find_path(lemin);
	if (!queue && !lemin->paths)
		error();
	store_path(queue, lemin);
	ft_putstr("Before:\n");
	print_adj(lemin->adj_list, lemin->graph_data->rooms);
	remove_rooms(lemin);
	ft_putstr("After:\n");
	print_adj(lemin->adj_list, lemin->graph_data->rooms);
	del_queue(&queue);

	// queue = find_path(lemin);
	// if (!queue && !lemin->paths)
	// 	error();
	// store_path(queue, lemin);
	// del_queue(&queue);
	int i;
	while(lemin->paths)
	{
		i = -1;
		while (++i < lemin->paths->len)
			ft_putstr(find_room(lemin->rooms, lemin->paths->moves[i])->name);
		ft_putchar('\n');
		lemin->paths = lemin->paths->next;
	}
}
