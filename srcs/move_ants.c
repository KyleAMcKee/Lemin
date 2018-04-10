/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:28:08 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/10 15:09:14 by kmckee           ###   ########.fr       */
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

    lcm = paths->len;
    while (paths->next)
    {
        lcm = (paths->next->len * lcm) / (gcd(paths->next->len, lcm));
        paths = paths->next;
    }
    return (lcm);
}

void    free_last(t_path *paths)
{
    t_path *current;

    while (paths->next)
    {
        current = paths;
        paths = paths->next;
    }
    current->next = NULL;
    free(paths);
}

int     number_of_paths(t_path *paths)
{
    int i;

    i = 0;
    while(paths)
    {
        paths = paths->next;
        i++;
    }
    return (i);
}

void    print_move(t_room *current)
{
    write(1, "L", 1);
    ft_putstr(ft_itoa(current->ants));
    write(1, "-", 1);
    ft_putstr(current->name);
    write(1, " ", 1);
}

void    move_ants(t_room *rooms, t_path *paths)
{
    int i;
    static int ant;
    t_room *current;
	t_room *previous;

    while (paths)
    {
        i = paths->len - 1;
        while (i > 0)
        {
            current = find_room(rooms, paths->moves[i]);
            previous = find_room(rooms, paths->moves[i - 1]);
            if (previous->ants)
            {
                //previous->ants--;
                if (current->end == 1)
                {
                    current->ants++;
                    previous->ants = 0;
                }
                else if (previous->start == 1)
                {
                    current->ants = ++ant;
                    previous->ants--;
                }
                else
                    current->ants = previous->ants;
                print_move(current);
                //add move to linked list;
            }
            i--;
        }
        paths = paths->next;
    }
}

void    manage_ants(t_lemin *lemin)
{
    int num_paths;
    int lcm;
    t_room *end_room;
    //t_list *ant_paths;

    num_paths = number_of_paths(lemin->paths);   
    end_room = find_room(lemin->rooms, lemin->paths->moves[lemin->paths->len - 1]);
    lcm = least_common_multiple(lemin->paths);
    while (end_room->ants < lemin->graph_data->ants)
    {
        while (lcm > lemin->graph_data->ants)
        {
            if (num_paths == 1)
                break;
            free_last(lemin->paths);
            num_paths = number_of_paths(lemin->paths);
            lcm = least_common_multiple(lemin->paths);
        }
        move_ants(lemin->rooms, lemin->paths);
        write(1, "\n", 1);
    }
}