/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:57:10 by kmckee            #+#    #+#             */
/*   Updated: 2018/03/31 20:13:12 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct  s_room {
    char    *name;
    int     room_number;
    int     start;
    int     end;
    int     visited;
    struct s_room  *next;
}               t_room;

typedef struct  s_graph {
    int     ants;
    int     start;
    int     end;
    int     rooms;
}               t_graph;

/*
** PARSING
*/

t_room  **parse_input(t_graph *graph);
void    get_room(char *room, t_graph *graph);
void	room_init(t_room *room, t_graph *graph);

/*
** ERROR
*/

void	error(void);

#endif
