/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:40 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/19 15:30:06 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	main(int argc, char **argv)
{
	t_list	list;
	int		len;

	len = argc;
	list.a = malloc(sizeof(int) * len);
	argc--;
	while (argc > 0)
	{
		list.a[argc - 1] = ft_atoi(argv[argc]);
		argc--;
	}
	while (argc < len - 1)
	{
		ft_putstr(itoa(list.a[argc]));
		argc++;
	}
	return (0);
}
