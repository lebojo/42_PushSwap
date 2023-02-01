/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/02/01 00:46:16 by jchapell         ###   ########.fr       */
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
char	*itoa(int val);
int		ft_atoi(const char *str);
int		find_nb(int *ls, int nb, int max);

/* CHECK				*/
int		validity_check(char c);

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
void	simple(t_list list, int argc);
void	algo_complex(t_list list, int chunk_size);
int		up_or_down(int place, int size);

#endif