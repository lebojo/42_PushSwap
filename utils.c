/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:26:57 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/19 15:14:31 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	write(1, "\n", 1);
}

int	tablen(int *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	intlen(int s)
{
	int	i;

	i = 0;
	if (s < 0)
	{
		s *= -1;
		i++;
	}
	while (s > 9)
	{
		s /= 10;
		i++;
	}
	return (i);
}

char	*itoa(int val)
{
	char	*num;
	char	*str;
	int		i;
	int		ii;

	str = malloc(sizeof(char) * intlen(val) + 2);
	num = "0123456789abcdef";
	ii = intlen(val) + 1;
	str[ii] = '\0';
	if (val < 0)
	{
		*str++ = '-';
		val = -val;
	}
	i = val;
	while (i)
	{
		str[--ii] = num[i % 10];
		i /= 10;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	res_sign;

	res = 0;
	res_sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			res_sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res_sign * res);
}
