/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:20:13 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/14 21:19:19 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_num_of_start(t_room *rooms)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp->start == FALSE)
		tmp = tmp->next;
	return (tmp->room_number);
}

int		check_if_part_of_path(t_lemin *lemin, int n)
{
	t_path	*paths;
	int		i;

	paths = lemin->paths;
	while (paths)
	{
		i = -1;
		while (++i < paths->len)
		{
			if (paths->moves[i] == n)
				return (TRUE);
		}
		paths = paths->next;
	}
	return (FALSE);
}

void	print_paths(t_lemin *lemin)
{
	int i;

	while (lemin->paths)
	{
		i = -1;
		ft_putstr("Len: ");
		ft_putnbr(lemin->paths->len);
		ft_putstr(" - Rooms: ");
		while (++i < lemin->paths->len)
			ft_putstr(find_room(lemin->rooms, lemin->paths->moves[i])->name);
		ft_putchar('\n');
		lemin->paths = lemin->paths->next;
	}
}

int	check_if_intermediary_comment(char **line)
{
	if (!line || !(*line))
		error();
	if (ft_strlen(*line) > 1 && (*line)[0] == '#')
	{
		ft_putstr((*line));
		ft_putchar('\n');
		if (!get_next_line(0, line))
			return (0);
	}
	return (1);
}
