/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:17:23 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/24 23:24:11 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	find_tiny(t_list list)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i <= list.top_a)
	{
		if (list.a[tmp] > list.a[i])
			tmp = i;
		i++;
	}
	return (tmp);
}

int	up_or_down(int place, int size)
{
	if (place + 1 > size / 2)
		return (1);
	else
		return (0);
}

void	simple(t_list list, int argc)
{
	int	i;

	while (list.top_a >= 0)
	{
		i = find_tiny(list);
		if (up_or_down(i, argc) == 1)
		{
			while (i++ < list.top_a)
				rotate(&list, 'a', 0);
			push(&list, 'b', 0);
		}
		else
		{
			while (i-- + 1 != 0)
				rev_rotate(&list, 'a', 0);
			push(&list, 'b', 0);
		}
	}
	while (list.top_b >= 0)
		push(&list, 'a', 0);
}
