/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:40 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/21 17:05:45 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	len = argc;
	init(&list, argc, argv);
	print_stacks(list, len);
	push(&list, 'b');
	push(&list, 'b');
	push(&list, 'b');
	print_stacks(list, len);
	double_rev_rotate(&list);
	print_stacks(list, len);
	return (0);
}
