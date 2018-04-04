/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:13:56 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/04 01:45:00 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	Parses # of ants and stores it in graph_data
**	NOTE: I still need to make sure that only digits were inputted
*/

static	void	get_number_of_ants(t_lemin *lemin)
{
	char	*line;

	lemin->graph_data = (t_graph *)ft_memalloc(sizeof(t_graph));
	get_next_line(0, &line);
	lemin->graph_data->ants = ft_atoi(line);
	if (lemin->graph_data->ants == 0)
		error();
	ft_strdel(&line);
}

/*
**	Rooms always come in with the following format
**	[string:Name]->[space]->[int:coord[0]]->space->[int:coord[1]]
**	NOTE: I still need to make sure coord[0][1] are only digits
*/

static	void	create_room(char *line, t_lemin *lemin, int start_end)
{
	char	**splitted_line;
	char	*name;
	int		coords[2];
	int		room_number;

	splitted_line = ft_strsplit(line, ' ');
	name = ft_strdup(splitted_line[0]);
	coords[0] = ft_atoi(splitted_line[1]);
	coords[1] = ft_atoi(splitted_line[2]);
	// This might be changed with a ft_2d_strdel
	ft_strdel(&splitted_line[0]);
	ft_strdel(&splitted_line[1]);
	ft_strdel(&splitted_line[2]);
	free(splitted_line);
	room_number = lemin->graph_data->rooms;
	lemin->graph_data->rooms++;
	add_room(&lemin->rooms, new_room(name, start_end, coords, room_number));
}

static	void	get_rooms(char	**line, t_lemin *lemin)
{
	int		start_end;
	
	while (get_next_line(0, line) > 0)
	{
		if (ft_strchr(*line, '-'))
			break ;
		if (ft_strlen(*line) > 4 && (*line)[0] == '#' && (*line)[1] == '#')
		{
			start_end = get_start_end(*line, lemin);
			ft_strdel(line);
			get_next_line(0, line);
			create_room(*line, lemin, start_end);
		}
		else if (ft_wordcount(*line) == 3)
			create_room(*line, lemin, 0);
		else
			error();
		ft_strdel(line);
	}
}

static	void	get_tunnels(char **line, t_lemin *lemin)
{
	char	**splitted_line;
	t_room	*tmp;

	lemin->adj_list = (t_vertices **)ft_memalloc(sizeof(t_vertices *) * lemin->graph_data->rooms);
	while (*line || get_next_line(0, line))
	{
		if (ft_strlen(*line) < 3 || ft_wordcountd(*line, '-') != 2)
			break ;
			// error();
		else
		{
			splitted_line = ft_strsplit(*line, '-');
			tmp = lemin->rooms;
			while (tmp)
			{
				if (ft_strequ(tmp->name, splitted_line[0]))
					add_vertice(&lemin->adj_list[tmp->room_number], new_vertice(tmp->room_number));
				if (ft_strequ(tmp->name, splitted_line[1]))
					add_vertice(&lemin->adj_list[tmp->room_number], new_vertice(tmp->room_number));
				tmp = tmp->next;
			}
			ft_strdel(&splitted_line[0]);
			ft_strdel(&splitted_line[1]);
			free(splitted_line);
		}
		ft_strdel(line);
	}
}

void			parse_input(t_lemin *lemin)
{
	char	*line;

	get_number_of_ants(lemin);
	lemin->rooms = NULL;
	get_rooms(&line, lemin);
	if (lemin->graph_data->rooms == 0 || lemin->graph_data->end == 0
			|| lemin->graph_data->start == 0)
		error();
	get_tunnels(&line, lemin);
	if (!lemin->adj_list)
		error();
}