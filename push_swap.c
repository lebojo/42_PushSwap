/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:40 by jchapell          #+#    #+#             */
/*   Updated: 2023/02/01 00:51:44 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	init(t_list *list, int argc, char **argv)
{
	int	i;

	i = 0;
	list[0].a = malloc(sizeof(int) * argc);
	list[0].b = malloc(sizeof(int) * argc);
	list[0].top_a = argc - 2;
	list[0].top_b = -1;
	list[0].size = argc - 2;
	argc--;
	while (argc > 0)
	{
		if (int_compare(ft_atoi(argv[argc]), list[0].a, i) == 0)
			return (0);
		list[0].a[i] = ft_atoi(argv[argc]);
		argc--;
		i++;
	}
	return (1);
}

int	chunk_size_calculator(int argc)
{
	int	size;

	size = 0;
	if (argc >= 500)
		size = argc / 15;
	else if (argc >= 100)
		size = argc / 5;
	else
		size = 5;
	return (size);
}

int	main(int argc, char **argv)
{
	t_list	list;
	int		check;

	check = init(&list, argc, argv);
	if (check != 0)
		algo_complex(list, chunk_size_calculator(argc));
	else
		ft_putstr("Error input");
	return (0);
}
//TODO: le check pour pas deux fois le même chiffre