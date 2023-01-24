/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:28:50 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/25 00:17:19 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	int_compare(int comp, int *list, int max)
{
	int	i;

	i = 0;
	while (i <= max)
	{
		if (list[i] == comp)
			return (0);
		i++;
	}
	return (1);
}

int	find_tiniest(t_list list, int *excl)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i <= list.top_a)
	{
		if (list.a[tmp] > list.a[i] && int_compare(list.a[i], excl, list.size))
			tmp = i;
		i++;
	}
	return (tmp);
}

int	moove_calculator(int i, int max)
{
	if (i >= max / 2)
	{
		return (max - i);
	}
	else
		return (i + 1);
}

void	algo_complex(t_list list, int chunk_size)
{
	int	*excl;
	int	i;
	int	tmp;
	int	cnt;

	excl = malloc(sizeof(int) * chunk_size);
	cnt = 0;
	while (cnt < list.size)
	{
		i = 0;
		while (i <= chunk_size)
			excl[i++] = find_tiniest(list, excl);
		i = 0;
		while (i <= chunk_size)
		{
			if (tmp > moove_calculator(excl[i], list.size))
				tmp = i;
			i++;
		}
		while (tmp < list.top_a)
		{
			if (up_or_down(i, list.size) == 1)
			{
				while (i++ < list.top_a)
					rotate(&list, 'a', 0);
				push(&list, 'b', 0);
			}
			else
			{
				while (i-- + 1 > 0)
					rev_rotate(&list, 'a', 0);
				push(&list, 'b', 0);
			}
		}
		cnt++;
	}
}
