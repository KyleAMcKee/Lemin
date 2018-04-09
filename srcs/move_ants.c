/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:28:08 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/09 15:14:14 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**  LCM = A * B / GCD(A, B)
*/

int     gcd(int a, int b)
{
    if (b == 0)
        return (a);
    return gcd(b, a % b); 
}

int     least_common_multiple(t_path *paths)
{
    int lcm;
    int i;

    lcm = paths->len;
    while (paths->next)
        lcm = (paths->next->len * lcm) / (gcd(paths->next->len, lcm));
    return (lcm);
}

void    free_last(t_path *paths)
{
    t_path *tmp;
    while (paths->next)
        paths = paths->next;
    free(paths);
    paths->next = NULL;
}

int     number_of_paths(t_path *paths)
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

void     find_end(t_graph *graph, t_path *paths)
{
    int i;

    while (paths)
    {
        i = 0;
        while (paths->moves[i] != graph->end)
            i++;
        paths->len = i;
        if (paths->len == 0)
            error();
        paths->next;
    }
}

void    move_ants(t_graph *graph, t_room *rooms, t_path *paths)
{
    int i;
    static int ant;
    t_room *current;
	t_room *previous;

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

void    manage_ants(t_graph *graph, t_room *rooms, t_path *paths)
{
    int num_paths;
    int i;
    int lcm;
    t_room *end_room;

    num_paths = number_of_paths(paths);
    find_room(rooms, paths->moves[0])->ants = graph->ants;
    lcm = least_common_multiple(paths)
    while (end_room->ants < graph->ants)
    {
        i = 0;
        while (lcm > graph->ants)
        {
            free_last(paths);
            num_paths = number_of_paths(paths);
            lcm = least_common_multiple(paths);
        }
        while (i < num_paths)
        {
            //find closest to end with ant;
            //move ant;
            //repeat until start;
            i++;
        }
    }
}