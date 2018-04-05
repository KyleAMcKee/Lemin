/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:56:25 by kmckee            #+#    #+#             */
/*   Updated: 2018/04/05 09:18:58 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(void)
{
	t_lemin	*lemin;

	lemin = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	parse_input(lemin);
	solve(lemin);
	return (0);
}
