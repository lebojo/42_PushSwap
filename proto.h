/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:47:42 by jchapell          #+#    #+#             */
/*   Updated: 2023/01/21 17:05:36 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include <unistd.h>
# include <stdlib.h>

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

/* INSTRUCTIONS			*/
void	swap(t_list *list, int ab);
void	push(t_list *list, char ab);
void	rotate(t_list *list, char ab);

/* INSTRUCTIONS	DOUBLE	*/
void	double_rotate(t_list *list);
void	double_swap(t_list *list);
void	double_rev_rotate(t_list *list);

/* INSTRUCTIONS	REVERSE	*/
void	rev_rotate(t_list *list, char ab);

#endif