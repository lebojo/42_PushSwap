/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:45 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/19 13:11:17 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <proto.h>

t_list	swap(t_list list, int ab)
{
	int	tmp;

	tmp = 0;
	if (ab == 'a')
	{
		tmp = list.a[0];
		list.a[0] = list.a[1];
		list.a[1] = tmp;
		ft_putstr("sa");
	}
	else if (ab == 'b')
	{
		tmp = list.b[0];
		list.b[0] = list.b[1];
		list.b[1] = tmp;
		ft_putstr("sb");
	}
	return (list);
}

t_list	push(t_list list, char ab)
{
	if (ab == 'a')
	{
		list.a[0] = list.b[0];
		list.b[0] = 0;
		ft_putstr("pa");
	}
	else if (ab == 'b')
	{
		list.b[0] = list.a[0];
		list.a[0] = 0;
		ft_putstr("pb");
	}
	return (list);
}

t_list	rotate(t_list list, char ab)
{
	int	first;
	int	i;

	first = 0;
	i = -1;
	if (ab == 'a')
	{
		first = list.a[0];
		while (list.a[++i + 1])
			list.a[i] = list.a[i + 1];
		list.a[i] = first;
	}
	else if (ab == 'b')
	{
		first = list.b[0];
		while (list.b[++i + 1])
			list.b[i] = list.b[i + 1];
		list.b[i] = first;
	}
	return (list);
}
