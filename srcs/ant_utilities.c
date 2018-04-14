/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 10:11:22 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/14 10:42:20 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**  LCM = A * B / GCD(A, B)
*/

int		gcd(int a, int b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

int		least_common_multiple(t_path *paths)
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

void	free_last(t_path *paths)
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

int		number_of_paths(t_path *paths)
{
	int i;

	i = 0;
	while (paths)
	{
		paths = paths->next;
		i++;
	}
	return (i);
}
