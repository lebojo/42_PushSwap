/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/03/01 17:31:20 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <unistd.h>
# include <stdlib.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_list{
	int	*a;
	int	top_a;
	int	*b;
	int	top_b;
	int	size;
}	t_list;

/* UTILS				*/
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
int		int_compare(int comp, int *list, int max);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);

/* CHECK				*/
int		validity_check(char *c);

/* INSTRUCTIONS			*/
void	swap(t_list *list, int ab, int dbl);
void	push(t_list *list, char ab, int dbl);
void	rotate(t_list *list, char ab, int dbl);

/* INSTRUCTIONS	DOUBLE	*/
void	double_rotate(t_list *list);
void	double_swap(t_list *list);
void	double_rev_rotate(t_list *list);

/* INSTRUCTIONS	REVERSE	*/
void	rev_rotate(t_list *list, char ab, int dbl);

/* ALGORITHM			*/
void	algo_complex(t_list list, int chunk_size);
int		up_or_down(int place, int size);
int		find_big(t_list list);
int		nb_to_index(int nb, t_list list);
int		move_calculator(int i, int max);
void	algo_simple(t_list list);
void	b_sort_to_a(t_list list);

#endif