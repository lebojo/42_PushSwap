/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:12:02 by jchapell          #+#    #+#             */
/*   Updated: 2023/02/24 20:34:11 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	simple_process(t_list *list, int big)
{
	if (up_or_down(big, list[0].top_a) == 1)
	{
		while (big++ < list[0].top_a)
			rotate(&list[0], 'a', 0);
		push(&list[0], 'b', 0);
	}
	else
	{
		while (big-- + 1 != 0)
			rev_rotate(&list[0], 'a', 0);
		push(&list[0], 'b', 0);
	}
}

void	align_a(t_list ls)
{
	if (ls.a[0] > ls.a[1])
		rotate(&ls, 'a', 0);
}

void	algo_simple(t_list list)
{
	int	big;
	int	i;

	while (list.top_a != 1)
	{
		i = -1;
		big = 0;
		while (++i <= list.top_a)
			if (list.a[i] > list.a[big])
				big = i;
		simple_process(&list, big);
	}
	align_a(list);
	b_sort_to_a(list);
}
