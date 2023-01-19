/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:06 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/19 13:26:05 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

t_list	rev_rotate(t_list list, char ab)
{
	int	last;
	int	i;

	last = 0;
	if (ab == 'a')
	{
		i = tablen(list.a);
		last = list.a[i];
		while (i > 0)
			list.a[i] = list.a[i-- - 1];
		list.a[i] = last;
		ft_putstr("rra");
	}
	else if (ab == 'b')
	{
		i = tablen(list.b);
		last = list.b[i];
		while (i > 0)
			list.b[i] = list.b[i-- - 1];
		list.b[i] = last;
		ft_putstr("rrb");
	}
	return (list);
}
