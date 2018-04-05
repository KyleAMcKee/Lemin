/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacency_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:52:04 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/04 17:15:06 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	void	create_adjlist(char *splitted_1, char *splitted_2, t_lemin *lemin)
{
	t_room	*tmp;
	t_room	*tmp2;
	
	tmp = lemin->rooms;
	while (tmp)
	{
		if (ft_strequ(tmp->name, splitted_1))
		{
			tmp2 = lemin->rooms;
			while(tmp2)
			{
				if (ft_strequ(tmp2->name, splitted_2))
					break ;
				tmp2 = tmp2->next;
			}
			add_vertice(&lemin->adj_list[tmp->room_number], new_vertice(tmp2->room_number));
			add_vertice(&lemin->adj_list[tmp2->room_number], new_vertice(tmp->room_number));
		}
		tmp = tmp->next;
	}
}

void	get_tunnels(char **line, t_lemin *lemin)
{
	char	**splitted_line;

	lemin->adj_list = (t_vertices **)ft_memalloc(sizeof(t_vertices *) * lemin->graph_data->rooms);
	while (*line || get_next_line(0, line))
	{
		if (ft_strlen(*line) > 2 || ft_wordcountd(*line, '-') == 2)
		{
			splitted_line = ft_strsplit(*line, '-');
			create_adjlist(splitted_line[0], splitted_line[1], lemin);
			ft_putstr(*line);
			ft_putchar('\n');
			ft_strdel(&splitted_line[0]);
			ft_strdel(&splitted_line[1]);
			free(splitted_line);
		}
		else if (ft_strlen(*line) > 1 && (*line)[0] == '#')
		{
			ft_putstr(*line);
			ft_putchar('\n');
		}
		else
			error();
		ft_strdel(line);
	}
}
