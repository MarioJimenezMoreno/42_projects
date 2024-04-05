/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:58:34 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/03 16:44:13 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *st_a)
{
	t_stack *first;
	t_stack *second;
	t_stack *last;

	if(st_a == NULL || st_a->next == NULL)
		return ;
	first = st_a;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = last;
	if(first->next != NULL)
		first->next->prev = first;
	if(last != NULL)
		last->next = second;
}

void	sb(t_stack *st_b)
{
	t_stack *first;
	t_stack *second;
	t_stack *last;

	if(st_b == NULL || st_b->next == NULL)
		return ;
	first = st_b;
	second = first->next;
	last = first->prev;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = last;
	if(first->next != NULL)
		first->next->prev = first;
	if(last != NULL)
		last->next = second;
}

void	ss(t_stack *st_a, t_stack *st_b)
{
	sa(st_a);
	sb(st_b);
}

void	pa(t_stack *st_a, t_stack *st_b)
{
	t_stack *second_a;
	t_stack *last_a;
	t_stack *last_b;

	second_a = st_a->next;
	last_a = st_a->prev;
	last_b = st_b->prev;
	last_a->next = second_a;
	second_a->prev = last;
	st_a->next = st_b;
	st_a->prev = last_b;
	last_b->next = st_a;
	st_b->prev = st_a;
}

void	pb(t_stack *st_a, t_stack *st_b)
{
	t_stack *second_b;
	t_stack *last_b;
	t_stack *last_a;

	second_b = st_b->next;
	last_b = st_b->prev;
	last_a = st_a->prev;
	last_b->next = second_b;
	second_b->prev = last;
	st_b->next = st_a;
	st_b->prev = last_a;
	last_a->next = st_b;
	st_a->prev = st_b;
}
