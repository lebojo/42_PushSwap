/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:28:50 by jchapell          #+#    #+#             */
/*   Updated: 2023/02/01 03:32:05 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

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

int *align_chunk(int *chunk, int del, int chunk_size)
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * chunk_size);
	while(i < chunk_size)
	{
		if (i >= del)
			res[i] = chunk[i + 1];
		else
			res[i] = chunk[i];
		i++;
	}
	free(chunk);
	return (res);
}

void	algo_complex(t_list list, int chunk_size)
{
	int	*chunk;
	int	i;
	int	tmp;
	int	ii;
	int	tmp2;

	chunk = malloc(sizeof(int) * chunk_size);
	tmp = list.top_a;
	while (list.top_a >= 0)
	{
		i = 0;
		while (i < chunk_size)
			chunk[i++] = find_tiniest(list, chunk, chunk_size);
		i = 0;
		ii = 0;
		while (i < chunk_size) //Pour chaque nb du chunk
		{
			while (ii < chunk_size - i) // pour chaque nb du chunk
			{
				if (move_calculator(find_nb(list.a, tmp, list.top_a), list.top_a) > move_calculator(find_nb(list.a, chunk[ii], list.top_a), list.top_a))
				{
					tmp = chunk[ii]; //TMP = l'index dans la list ave le moins de move
					tmp2 = ii;
				}
				ii++;
			}
			chunk = align_chunk(chunk, tmp2, chunk_size - i);
			tmp = find_nb(list.a, tmp, list.top_a);
			if (move_calculator(tmp, list.top_a) >= list.top_a / 2) //Regarde si rotate ou rev_rotate
			{
				tmp = list.a[tmp]; //Prend le nombre a push
				while (list.a[list.top_a] != tmp) // On fait l'action tant qu' qu'il est pas au top
					rotate(&list, 'a', 0);
				push(&list, 'b', 0); //Push
			}
			else
			{
				tmp = list.a[tmp]; //^ Same que en haut ^
				while (list.a[list.top_a] != tmp)
					rev_rotate(&list, 'a', 0);
				push(&list, 'b', 0);
			}
			break ;
			i++;
		}
		break ;
	}
}
