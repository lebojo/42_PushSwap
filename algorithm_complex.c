/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:28:50 by jchapell          #+#    #+#             */
/*   Updated: 2023/02/09 18:34:33 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	find_tiniest(t_list list, int *excl, int chunk_size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 2147483647;
	while (i <= list.top_a)
	{
		if (tmp > list.a[i] && int_compare(list.a[i], excl, chunk_size) == 1)
			tmp = list.a[i];
		if (tmp < list.a[i] && int_compare(list.a[i], excl, chunk_size) == 0)
			tmp = 2147483647;
		i++;
	}
	return (tmp);
}

int	move_calculator(int i, int max)
{
	if (i >= max / 2)
	{
		return (max - i);
	}
	else
		return (i + 1);
}

void	align_chunk(int **chunk, int chunk_size, t_list ls, int i_start)
{
	int	tmp;
	int	i;

	i = i_start;
	while (i < chunk_size - 1)
	{
		if (move_calculator(nb_to_index(chunk[0][i], ls), ls.top_a)
		> move_calculator(nb_to_index(chunk[0][i + 1], ls), ls.top_a))
		{
			tmp = chunk[0][i];
			chunk[0][i] = chunk[0][i + 1];
			chunk[0][i + 1] = tmp;
			i = i_start;
		}
		else
			i++;
	}
}

void	b_sort_to_a(t_list list)
{
	int	i;

	while (list.top_b >= 0)
	{
		i = find_tiny(list);
		if (up_or_down(i, list.top_b) == 1)
		{
			while (i++ < list.top_b)
				rotate(&list, 'b', 0);
			push(&list, 'a', 0);
		}
		else
		{
			while (i-- + 1 != 0)
				rev_rotate(&list, 'b', 0);
			push(&list, 'a', 0);
		}
	}
}

void	algo_complex(t_list list, int chunk_size)
{
	int	i_chunk;
	int	*chunk;
	int	i;

	while (list.top_a > chunk_size)
	{
		i_chunk = 0;
		chunk = malloc(sizeof(int) * chunk_size);
		while (i_chunk != chunk_size)
			chunk[i_chunk++] = find_tiniest(list, chunk, chunk_size);
		align_chunk(&chunk, chunk_size, list, 0);
		i_chunk = 0;
		while (i_chunk != chunk_size)
		{
			i = nb_to_index(chunk[i_chunk], list);
			if (up_or_down(i, list.top_a) == 1)
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
			i_chunk++;
			align_chunk(&chunk, chunk_size, list, i_chunk);
		}
		free(chunk);
		chunk = NULL;
	}
	while (list.top_a >= 0)
		push(&list, 'b', 0);
	b_sort_to_a(list);
}
