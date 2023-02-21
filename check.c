/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:43:34 by jchapell          #+#    #+#             */
/*   Updated: 2023/02/21 21:32:50 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

int	validity_check(char *c)
{
	int tmp;
	
	while (*c && *c == ' ')
		c++;
	tmp = ft_atoi(c);
	if (ft_strcmp(c, ft_itoa(tmp)) == 1)
		return (1);
	return (0);
}
