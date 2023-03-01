/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:06 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/01 16:47:42 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	rev_rotate(t_list *list, char ab, int dbl)
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
			ft_putstr("rra");
	}
	else if (ab == 'b')
	{
		first = list[0].b[0];
		while (list[0].b[++i + 1])
			list[0].b[i] = list[0].b[i + 1];
		list[0].b[i] = first;
		if (!dbl)
			ft_putstr("rrb");
	}
}
