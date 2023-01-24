/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:06 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/24 21:49:18 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	rotate(t_list *list, char ab, int dbl)
{
	int	last;
	int	i;

	last = 0;
	if (ab == 'a')
	{
		last = list[0].a[list[0].top_a];
		i = list[0].top_a + 1;
		while (--i > 0)
			list[0].a[i] = list[0].a[i - 1];
		list[0].a[0] = last;
		if (!dbl)
			ft_putstr("ra");
	}
	else if (ab == 'b')
	{
		last = list[0].b[list[0].top_b];
		i = list[0].top_b + 1;
		while (--i > 0)
			list[0].b[i] = list[0].b[i - 1];
		list[0].b[0] = last;
		if (!dbl)
			ft_putstr("rb");
	}
}
