/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:06 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/21 16:43:41 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	rev_rotate(t_list *list, char ab)
{
	int	last;
	int	i;

	last = 0;
	if (ab == 'a')
	{
		i = tablen(list[0].a) + 1;
		last = list[0].a[i - 1];
		while (--i > 0)
			list[0].a[i] = list[0].a[i - 1];
		list[0].a[i] = last;
		ft_putstr("rra");
	}
	else if (ab == 'b')
	{
		i = tablen(list[0].b) + 1;
		last = list[0].b[i - 1];
		while (--i > 0)
			list[0].b[i] = list[0].b[i - 1];
		list[0].b[i] = last;
		ft_putstr("rrb");
	}
}
