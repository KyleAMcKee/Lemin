/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:46:43 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/09 17:15:55 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path		*new_path(int **n, int length)
{
	t_path	*path;
	int		i;

	i = -1;
	path = (t_path *)ft_memalloc(sizeof(t_path));
	path->len = length;
	path->moves = (int *)ft_memalloc(sizeof(int) * length);
	while (++i < length)
		path->moves[i] = (*n)[i];
	path->next = NULL;
	free(*n);
	return (path);
}

void		add_path(t_path **paths, t_path *new_path)
{
	t_path	*tmp;

	if (paths && *paths && new_path)
	{
		tmp = *paths;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_path;
	}
	else if (new_path && (!paths || !(*paths)))
		*paths = new_path;
}

void		delone_path(t_path **paths)
{
	t_path	*tmp;

	if (paths && *paths)
	{
		tmp = *paths;
		*paths = (*paths)->next;
		free(tmp);
		tmp = NULL;
	}
}

void		del_paths(t_path **paths)
{
	if (paths)
	{
		while (*paths)
			delone_path(paths);
	}
	paths = NULL;
}
