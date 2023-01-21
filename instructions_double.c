/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:47 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/21 17:06:47 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	double_swap(t_list *list)
{
	//EN MEME TEMPS
	ft_putstr("ss");
}

void	double_rotate(t_list *list)
{
	rotate(list, 'a');
	rotate(list, 'b');
	ft_putstr("rr");
}

void	double_rev_rotate(t_list *list)
{
	rev_rotate(list, 'a');
	rev_rotate(list, 'b');
	ft_putstr("rrr");
}
