/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:28:08 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/10 14:37:02 by kmckee           ###   ########.fr       */
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

void    print_moves(t_ant_moves *ant_moves)
{
    while (ant_moves)
    {
        write(1, "L", 1);
        ft_putstr(ft_itoa(ant_moves->ant_id));
        write(1, "-", 1);
        ft_putstr(ant_moves->room);
        if (ant_moves->last != 1)
            write(1, " ", 1);
        else
            write(1, "\n", 1);
        ant_moves = ant_moves->next;
    }
}

void    add_move(t_room *current, t_ant_moves *ant_paths)
{
    t_ant_moves *new_node;

    while (ant_paths)
        ant_paths = ant_paths->next;
    new_node = (t_ant_moves*)malloc(sizeof(t_ant_moves));
    printf("hola\n");
    ant_paths->next = new_node;
    new_node->next = NULL;
    new_node->ant_id = current->ants;
    new_node->room = current->name;
    if (current->end == 1)
        new_node->last = 1;
    else
        new_node->last = 0;
}

void    move_ants(t_room *rooms, t_path *paths, t_ant_moves *ant_paths)
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
                add_move(current, ant_paths);
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
    t_ant_moves *ant_paths;

    num_paths = number_of_paths(lemin->paths);   
    end_room = find_room(lemin->rooms, lemin->paths->moves[lemin->paths->len - 1]);
    lcm = least_common_multiple(lemin->paths);
    ant_paths = (t_ant_moves*)malloc(sizeof(t_ant_moves));
    ant_paths->next = NULL;
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
        move_ants(lemin->rooms, lemin->paths, ant_paths);
        print_moves(ant_paths);
    }
}