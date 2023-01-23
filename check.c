/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:43:34 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/23 15:22:05 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	validity_check(char c)
{
	if ((c > 'a' && c < 'z') || c > 'A' && c < 'Z')
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}
