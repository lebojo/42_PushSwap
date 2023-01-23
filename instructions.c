/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:45 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/23 16:05:13 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	swap(t_list *list, int ab, int dbl)
{
	int	tmp;

	tmp = 0;
	if (ab == 'a' && list[0].top_a > 1)
	{
		tmp = list[0].a[list[0].top_a];
		list[0].a[list[0].top_a] = list[0].a[list[0].top_a - 1];
		list[0].a[list[0].top_a - 1] = tmp;
		if (!dbl)
			ft_putstr("sa");
	}
	else if (ab == 'b' && list[0].top_b > 1)
	{
		tmp = list[0].b[list[0].top_b];
		list[0].b[list[0].top_b] = list[0].b[list[0].top_b - 1];
		list[0].b[list[0].top_b - 1] = tmp;
		if (!dbl)
			ft_putstr("sb");
	}
}

void	push(t_list *list, char ab, int dbl)
{
	if (ab == 'a' && list[0].b[list[0].top_b])
	{
		list[0].a[++list[0].top_a] = list[0].b[list[0].top_b];
		list[0].b[list[0].top_b--] = 0;
		if (!dbl)
			ft_putstr("pa");
	}
	else if (ab == 'b' && list[0].a[list[0].top_a])
	{
		list[0].b[++list[0].top_b] = list[0].a[list[0].top_a];
		list[0].a[list[0].top_a--] = 0;
		if (!dbl)
			ft_putstr("pb");
	}
}

void	rotate(t_list *list, char ab, int dbl)
{
	int	first;
	int	i;

	first = 0;
	i = -1;
	if (ab == 'a')
	{
		first = list[0].a[0];
		while (list[0].a[++i + 1])
			list[0].a[i] = list[0].a[i + 1];
		list[0].a[i] = first;
		if (!dbl)
			ft_putstr("ra");
	}
	else if (ab == 'b')
	{
		first = list[0].b[0];
		while (list[0].b[++i + 1])
			list[0].b[i] = list[0].b[i + 1];
		list[0].b[i] = first;
		if (!dbl)
			ft_putstr("rb");
	}
}
