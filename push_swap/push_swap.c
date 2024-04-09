/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:14:29 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/08 21:18:49 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_swap()
{}

static void create_stack(t_stack **st_a, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		ft_lstadd_back(st_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	ft_lstlast(*st_a)->next = *st_a;
	
}

static void	print_nums(int argc, t_stack *st_a)
{
	int num;
	int i;

	i = 1;
	while (st_a && i < argc)
	{
		num = st_a->value;
		printf("%d", num);
		st_a = st_a->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack *st_a;
	t_stack *st_b;
	
	st_a = NULL;
	st_b = NULL;
	if (argc <= 1)
		return (0);
	create_stack(&st_a, argv);
	print_nums(argc, st_a);
	return (0);
}
