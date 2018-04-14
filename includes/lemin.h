/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:57:10 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/14 10:13:03 by kmckee           ###   ########.fr       */
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

typedef	struct		s_path
{
	int				*moves;
	int				len;
	struct s_path	*next;
}					t_path;

typedef	struct			s_vertices
{
	int					n;
	struct s_vertices	*next;
}						t_vertices;

typedef struct		s_room
{
	char			*name;
	int				room_number;
	int				coords[2];
	int				start;
	int				end;
	int				ants;
	int				ant_id;
	int				visited;
	int				parent;
	int				distance;
	struct s_room	*next;
}					t_room;

typedef struct	s_graph
{
	int			ants;
	int			start;
	int			end;
	int			rooms;
}				t_graph;

typedef	struct	s_lemin
{
	t_room		*rooms;
	t_graph		*graph_data;
	t_vertices	**adj_list;
	t_path		*paths;
}				t_lemin;

typedef struct			s_queue_item
{
	t_room				*room;
	struct s_queue_item	*next;
}						t_queue_item;

typedef struct		s_queue
{
	t_queue_item	*first;
	t_queue_item	*last;
}					t_queue;

/*
**	MACROS
*/

# define TRUE 1
# define FALSE 0
# define CURRENT queue->first->room

/*
**	PARSING
*/

void		parse_input(t_lemin *lemin);
int			get_start_end(char *line, t_lemin *lemin);
void		get_tunnels(char **line, t_lemin *lemin);

/*
**  QUEUE
*/

t_queue		*init_queue(t_lemin *lemin);
void		enqueue(t_queue *queue, t_room *room);
void		dequeue(t_queue *queue);
int			queue_empty(t_queue *queue);
void		del_queue(t_queue **queue);

/*
**	BFS
*/

void		solve(t_lemin *lemin);

/*
**	UTILITIES
*/

void		error(void);
void		only_digits(char *s);
void		finalize_lemin(t_lemin *lemin);
int			get_num_of_start(t_room *rooms);
int			check_if_part_of_path(t_lemin *lemin, int n);
void		check_if_intermediary_comment(char **line);

t_room		*find_room(t_room *rooms, int i);
void		initialize_rooms(t_lemin *lemin, t_room *rooms);
t_room		*new_room(char *name, int start_end, int coords[2], int rn);
void		add_room(t_room **rooms, t_room *new_room);
void		delone_room(t_room **rooms);
void		del_rooms(t_room **rooms);

t_vertices	*new_vertice(int n);
void		add_vertice(t_vertices **adj_list, t_vertices *new_vertice);
void		delone_vertice(t_vertices **adj_list);
void		del_vertices(t_vertices ***adj_list, int len);

t_path		*new_path(int **n, int length);
void		add_path(t_path **paths, t_path *new_path);
void		delone_path(t_path **paths);
void		del_paths(t_path **paths);

int     	gcd(int a, int b);
int     	least_common_multiple(t_path *paths);
void    	free_last(t_path *paths);
int     	number_of_paths(t_path *paths);

/*
**  MOVE ANTS
*/

void		manage_ants(t_lemin *lemin);

#endif
