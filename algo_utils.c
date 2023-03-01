/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:17:23 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/01 17:31:21 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	find_big(t_list list)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i <= list.top_b)
	{
		if (list.b[tmp] < list.b[i])
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

int	nb_to_index(int nb, t_list list)
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

int	move_calculator(int i, int max)
{
	if (i >= max / 2)
	{
		return (max - i);
	}
	else
		return (i + 1);
}
