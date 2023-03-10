/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:47 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/23 14:39:55 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	double_swap(t_list *list)
{
	swap(list, 'a', 1);
	swap(list, 'b', 1);
	ft_putstr("ss");
}

void	double_rotate(t_list *list)
{
	rotate(list, 'a', 1);
	rotate(list, 'b', 1);
	ft_putstr("rr");
}

void	double_rev_rotate(t_list *list)
{
	rev_rotate(list, 'a', 1);
	rev_rotate(list, 'b', 1);
	ft_putstr("rrr");
}
