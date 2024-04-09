/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:27:33 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/08 18:12:25 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	push_swap(t_stack *st_a);
int		ft_atoi(char *nptr);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	sa(t_stack *st_a);
void	sb(t_stack *st_b);
void	ss(t_stack *st_a, t_stack *st_b);
void	pa(t_stack *st_a, t_stack *st_b);
void	pb(t_stack *st_a, t_stack *st_b);
void	ra(t_stack *st_a);
void	rb(t_stack *st_b);
void	rr(t_stack *st_a, t_stack *st_b);
void	rra(t_stack *st_a);
void	rrb(t_stack *st_b);
void	rrr(t_stack *st_a, t_stack *st_b);
