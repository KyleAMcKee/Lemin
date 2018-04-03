/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:54:15 by kmckee            #+#    #+#             */
/*   Updated: 2018/03/31 20:14:34 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char   *extract_room(char *room)
{
    int i;
    int amount;
    char *ret;

    i = 0;
    amount = 0;
    while (room[amount] != ' ')
        amount++;
    ret = (char*)malloc(sizeof(char) * amount);
    ret[amount] = '\0';
    while (i < amount)
    {
        ret[i] = room[i];
        i++;
    }
    return (ret);
}

int    find_start_end(char *room, t_graph *graph)
{
    if (ft_strequ(&room[2] , "start"))
    {
        if (graph->start == 1)
            error();
        graph->start = 1;
        free(room);
        return (1);
    }
    else if (ft_strequ(&room[2], "end"))
    {
        if (graph->end == 1)
            error();
        graph->end = 1;
        free(room);
        return (2);
    }
    else
        error();
    free(room);
    return (0);
}

void    new_room(t_room *room, t_graph *graph, char *line, int start_end)
{
    t_room  *new_room;
    static int i;

    printf("%i\n", ++i);
    new_room = (t_room*)malloc(sizeof(t_room));
    room->next = new_room;
    room_init(new_room, graph);
    room->name = extract_room(line);
    if (start_end == 1)
        room->start = 1;
    if (start_end == 2)
        room->end = 1;
}

t_room    **parse_input(t_graph *graph)
{
    char    *line;
    int     start_end;
    t_room  **rooms;

    rooms = (t_room**)malloc(sizeof(t_room*));
    get_next_line(0, &line);
    graph->ants = ft_atoi(line);
    printf("ants: %i\n", graph->ants);
    free (line);
    while (get_next_line(0, &line))
    {
        if (line[0] == '#')
        {
            if (line[1] == '#' && (graph->end == 0 || graph->start == 0))
            {
                start_end = find_start_end(line, graph);
                get_next_line(0, &line);
                new_room(*rooms, graph, line, start_end);
                *rooms = (*rooms)->next;
            }
        }
        else if (!ft_strchr(line, '-') && ft_strlen(line) > 1)
        {
            new_room((*rooms), graph, line, 0);
            *rooms = (*rooms)->next;
        }
        else if (ft_strchr(line, '-'))
        {
            if (graph->start == 0 || graph->end == 0)
                error();
            //Build adjacency list
        }
        free(line);
    }
    return (rooms);
}