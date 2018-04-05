/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:28:08 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/05 16:36:24 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     number_of_paths(t_paths *paths)
{
    int i;

    i = 0;
    while(paths)
        paths = paths->next;
    return (i);
}

void    print_move(t_room *current)
{
    write(1, "L", 1);
    write(1, current, 1);
    write(1, "-", 1);
    write(1, current->name, 1);
}

void     find_end(t_graph *graph, t_paths *paths)
{
    int i;

    while (paths)
    {
        i = 0;
        while (path->moves[i] != graph->end)
            i++;
        paths->len = i;
        if (paths->len == 0)
            error();
        paths->next;
    }
}

void    move_ants(t_graph *graph, t_room *rooms, t_paths *paths)
{
    int i;
    static int ant;
    t_room *current;

    ant = 1;
    while (paths)
    {
        i = paths->len;
        while (i > 0)
        {
            current = find_room(rooms, paths->moves[i]);
            previous = find_room(rooms, paths->moves[i - 1]);
            if (previous->ants)
            {
                previous->ants--;
                print_move(current);
            }
            i--;
        }
    }
}

void    move_ants(t_graph *graph, t_room *rooms, t_paths *paths)
{
    int arr_size;
    int num_paths;

    //arr_size = find_end(graph, moves);
    //end_room = find_room(rooms, moves[arr_size]);
    num_paths = number_of_paths(paths);
    find_room(rooms, moves[0])->ants = graph->ants;
    while (end_room->ants < graph->ants)
    {
        //find closest to end with ant;
        //move ant;
        //repeat until start;
    }
}