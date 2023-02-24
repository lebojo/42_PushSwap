/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:43:34 by jchapell          #+#    #+#             */
/*   Updated: 2023/02/24 20:41:39 by jchapell         ###   ########.fr       */
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
	int		tmp;
	char	*tmp_c;

	while (*c && *c == ' ')
		c++;
	tmp = ft_atoi(c);
	tmp_c = ft_itoa(tmp);
	if (ft_strcmp(c, tmp_c) == 1)
	{
		free(tmp_c);
		return (1);
	}
	free(tmp_c);
	return (0);
}
