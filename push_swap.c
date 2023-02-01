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

/*
TODO:
Faire que ca marche avec les 0 et les chifre neg
ALGO:
trouver le plus proche du haut de la stack dans les chunk 
(size/10 = nb de chunk, et ) 
et le plus proche du bas, pour savoir le quel bouger en premier, puis sur le
deuxieme chunk etc..
*/

#include "proto.h"

void	ft_puttab(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	init(t_list *list, int argc, char **argv)
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
		list[0].a[i] = ft_atoi(argv[argc]);
		argc--;
		i++;
	}
}

int	chunk_size_calculator(int argc)
{
	int	size;

	size = 0;
	if (argc > 10)
	{
		size = argc / 10;
	}
	else
		size = 1;
	return (size);
}

void	print_stacks(t_list list, int len)
{
	int	i;

	i = 0;
	if (DEBUG == 1)
	{
		ft_puttab("\n");
		ft_puttab("\033[0;32mA");
		ft_puttab("\t");
		ft_puttab("\033[1;33mB");
		ft_puttab("\n\033[1;36m---bot---");
		ft_puttab("\n\033[0;32m");
		while (i < len - 1)
		{
			ft_puttab(itoa(list.a[i]));
			ft_puttab("\t\033[1;33m");
			ft_puttab(itoa(list.b[i]));
			ft_puttab("\n\033[0;32m");
			i++;
		}
		ft_puttab("\033[0m");
	}
}

int	main(int argc, char **argv)
{
	t_list	list;
	int		len;
	int		i;

	len = argc;
	init(&list, argc, argv);
	print_stacks(list, len);
	algo_complex(list, chunk_size_calculator(argc));
	print_stacks(list, len);
	return (0);
}
