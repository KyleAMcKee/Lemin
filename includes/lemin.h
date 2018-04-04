/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:57:10 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/04 04:26:09 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>

/*
**	STRUCTURES
*/

typedef	struct	s_vertices
{
	int		n;
	struct s_vertices	*next;
}				t_vertices;

typedef struct  s_room
{
    char    *name;
    int     room_number;
	int		coords[2];
    int     start;
    int     end;
    int     visited;
    struct s_room	*next;
}               t_room;

typedef struct  s_graph
{
    int     ants;
    int     start;
    int     end;
    int     rooms;
}               t_graph;

typedef	struct	s_lemin
{
	t_room		*rooms;
	t_graph		*graph_data;
	t_vertices	**adj_list;
	// char		**name_number;
}				t_lemin;

/*
**	MACROS
*/

# define TRUE 1
# define FALSE 0

/*
**	PARSING
*/

void		parse_input(t_lemin *lemin);
int			get_start_end(char *line, t_lemin *lemin);

/*
**	BFS
*/

int			*find_best_solution(t_lemin *lemin);

/*
**	UTILITIES
*/

void	error(void);

t_room		*new_room(char *name, int start_end, int coords[2], int room_number);
void		add_room(t_room **rooms, t_room *new_room);
void		delone_room(t_room **rooms);
void		del_rooms(t_room **rooms);
t_vertices	*new_vertice(int n);
void		add_vertice(t_vertices **adj_list, t_vertices *new_vertice);
void		delone_vertice(t_vertices **adj_list);
void		del_vertices(t_vertices **adj_list);

#endif
