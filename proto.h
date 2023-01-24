/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/24 21:56:52 by jchapell         ###   ########.fr       */
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
}	t_list;

/* UTILS				*/
void	ft_putstr(char *s);
int		tablen(int *s);
char	*itoa(int val);
int		ft_atoi(const char *str);

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

#endif