/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:40 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/05 18:12:50 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	init(t_list *list, int argc, char **argv)
{
	int	i;

	i = 0;
	list[0].a = malloc(sizeof(int) * (argc - 1));
	if (!list[0].a)
		return (0);
	list[0].b = malloc(sizeof(int) * (argc - 1));
	if (!list[0].b)
		return (0);
	list[0].top_a = argc - 2;
	list[0].top_b = -1;
	list[0].size = argc - 2;
	argc--;
	while (argc > 0)
	{
		if (validity_check(argv[argc]) == 1
			|| int_compare(ft_atoi(argv[argc]), list[0].a, i) == 0)
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

	size = 5;
	if (argc >= 500)
		size = argc / 15;
	else if (argc >= 100)
		size = argc / 5;
	return (size);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	write(1, "\n", 1);
}

int	analyze(t_list list)
{
	int	i;

	i = 0;
	while (++i <= list.top_a)
		if (list.a[i - 1] < list.a[i])
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	list;
	int		check;

	check = init(&list, argc, argv);
	if (check == 0)
		write(2, "Error\n", 6);
	else if (analyze(list) == 1)
	{
		if (argc > 6)
			algo_complex(list, chunk_size_calculator(argc));
		else
			algo_simple(list);
	}
	free(list.a);
	free(list.b);
	return (0);
}