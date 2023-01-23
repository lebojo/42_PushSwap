/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:40 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/23 16:36:26 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TODO:
Faire que ca marche avec les 0 et les chifre neg
*/

#include "proto.h"

void	init(t_list *list, int argc, char **argv)
{
	list[0].a = malloc(sizeof(int) * argc);
	list[0].b = malloc(sizeof(int) * argc);
	list[0].top_a = argc - 2;
	list[0].top_b = -1;
	argc--;
	while (argc > 0)
	{
		list[0].a[argc - 1] = ft_atoi(argv[argc]);
		argc--;
	}
}

int	find_tiny(t_list list)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i <= list.top_a)
	{
		if (list.a[tmp] > list.a[i])
			tmp = i;
		i++;
	}
	return (tmp);
}

int	up_or_down(int place, int size)
{
	if (place + 1 > size / 2)
		return (1);
	else
		return (0);
}

void	print_stacks(t_list list, int len)
{
	int	i;

	i = 0;
	ft_putstr("\n");
	ft_putstr("\033[0;32mA");
	ft_putstr("\t");
	ft_putstr("\033[1;33mB");
	ft_putstr("\n\033[1;36m---bot---");
	ft_putstr("\n\033[0;32m");
	while (i < len - 1)
	{
		ft_putstr(itoa(list.a[i]));
		ft_putstr("\t\033[1;33m");
		ft_putstr(itoa(list.b[i]));
		ft_putstr("\n\033[0;32m");
		i++;
	}
	ft_putstr("\033[0m");
}

int	main(int argc, char **argv)
{
	t_list	list;
	int		len;
	int		i;

	len = argc;
	init(&list, argc, argv);
	print_stacks(list, len);
	while (list.top_a >= 0)
	{
		i = find_tiny(list);
		if (up_or_down(i, argc) == 1)
		{
			while (i < list.top_a)
			{
				rev_rotate(&list, 'a', 0);
				i++;
			}
			push(&list, 'b', 0);
			print_stacks(list, len);
		}
		else
		{
			while (i + 1 != 0)
			{
				rotate(&list, 'a', 0);
				i--;
			}
			push(&list, 'b', 0);
			print_stacks(list, len);
		}
	}
	while (list.top_b >= 0)
		push(&list, 'a', 0);
	print_stacks(list, len);
	return (0);
}
