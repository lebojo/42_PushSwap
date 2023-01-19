/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/19 15:15:35 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list{
	int	*a;
	int	*b;
}	t_list;

/* UTILS				*/
void	ft_putstr(char *s);
int		tablen(int *s);
char	*itoa(int val);
int		ft_atoi(const char *str);

/* INSTRUCTIONS			*/
t_list	swap(t_list list, int ab);
t_list	push(t_list list, char ab);
t_list	rotate(t_list list, char ab);

/* INSTRUCTIONS	DOUBLE	*/
t_list	double_rotate(t_list list);
t_list	double_swap(t_list list);

/* INSTRUCTIONS	REVERSE	*/
t_list	rev_rotate(t_list list, char ab);

#endif