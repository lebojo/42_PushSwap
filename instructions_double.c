/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:54:47 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/19 13:11:49 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

t_list	double_swap(t_list list)
{
	list = swap(list, 'a');
	list = swap(list, 'b');
	return (list);
}

t_list	double_rotate(t_list list)
{
	list = rotate(list, 'a');
	list = rotate(list, 'b');
	return (list);
}
