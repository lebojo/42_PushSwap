/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:12:02 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/05 19:48:45 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	simple_process(t_list *list, int tiny)
{
	if (up_or_down(tiny, list->top_a) == 1)
	{
		while (tiny++ < list->top_a)
			rotate(&list[0], 'a', 0);
		push(&list[0], 'b', 0);
	}
	else
	{
		while (tiny-- + 1 != 0)
			rev_rotate(&list[0], 'a', 0);
		push(&list[0], 'b', 0);
	}
}

void	align_a(t_list *ls)
{
	if (ls->a[0] < ls->a[1])
		rotate(ls, 'a', 0);
}

void	algo_simple(t_list list)
{
	int	tiny;
	int	i;

	while (list.top_a != 1)
	{
		i = -1;
		tiny = 0;
		while (++i <= list.top_a)
			if (list.a[i] < list.a[tiny])
				tiny = i;
		simple_process(&list, tiny);
	}
	align_a(&list);
	b_sort_to_a(list);
}
//TODO: neg et 0