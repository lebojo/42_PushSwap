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
#include <stdio.h>

int	int_compare(int comp, int *list, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (list[i] == comp)
			return (0);
		i++;
	}
	return (1);
}

int	find_tiniest(t_list list, int *excl, int chunk_size)
{
	int	i;
	int	tmp;
	int tmp2;

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


int nb_to_index(int nb, t_list list)
{
	int	i;

	i = 0;
	while (i <= list.top_a)
	{
		if (list.a[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

void align_chunk(int **chunk, int chunk_size, t_list ls, int i_start) //le i_start c'est comme ça ceux avant on les touches pas parce qu'on les a deja push
{
	int	tmp;
	int	i;

	i = i_start;
	while (i < chunk_size - 1)
	{
		if (move_calculator(nb_to_index(chunk[0][i], ls), ls.top_a) > move_calculator(nb_to_index(chunk[0][i + 1], ls), ls.top_a))
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

void print_chunk(t_list ls, int *chunk, int chunk_size)
{
	int	i_chunk;

	i_chunk = -1;
	printf("DONNES TECH:\nCHUNK_SIZE: %i\nTOP_A: %i\n", chunk_size, ls.top_a);
	while (++i_chunk != chunk_size)
		printf("POSITION: %i	NB: %i	NB_MOVE:%i\n", nb_to_index(chunk[i_chunk], ls), chunk[i_chunk], move_calculator(nb_to_index(chunk[i_chunk], ls), ls.top_a));	
}

int	find_tiny(t_list list)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i <= list.top_b)
	{
		if (list.b[tmp] > list.b[i])
			tmp = i;
		i++;
	}
	return (tmp);
}

void b_sort_to_a(t_list list)
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
	int i_chunk;
	int *chunk;
	int i;

	while (list.top_a > chunk_size) //Tant qu'on arrive pas au dernier chunk
	{
		i_chunk = 0;
		chunk = malloc(sizeof(int) * chunk_size);
		//On construit le chunk:
		while (i_chunk != chunk_size)
			chunk[i_chunk++] = find_tiniest(list, chunk, chunk_size);
		align_chunk(&chunk, chunk_size, list, 0); // = Tri du moins de mouvements au plus de mouvement dans le chunk
		i_chunk = 0;
		while (i_chunk != chunk_size)
		{
			i = nb_to_index(chunk[i_chunk], list); // i = index dans la list
			if (up_or_down(i, list.top_a) == 1) //Rotate ou Rev_rotate
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
