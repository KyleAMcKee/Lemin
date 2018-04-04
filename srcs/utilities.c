/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:03:46 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/04 01:43:26 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

/*
**	This function is only called when ## is found and it determines
**	whether start or end will be inputted next
**	if none of these is found, input is invalid
*/

int		get_start_end(char *line, t_lemin *lemin)
{
    if (ft_strequ(&line[2] , "start"))
    {
        if (lemin->graph_data->start == 1)
            error();
        lemin->graph_data->start = 1;
        return (1);
    }
    else if (ft_strequ(&line[2], "end"))
    {
        if (lemin->graph_data->end == 1)
            error();
        lemin->graph_data->end = 1;
        return (2);
    }
    else
	{
        error();
		return (0);
	}
}
