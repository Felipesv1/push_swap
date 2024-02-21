/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:10 by felperei          #+#    #+#             */
/*   Updated: 2024/02/21 14:41:37 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

static void	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit (-1);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (-1);
	check_args(av, ac);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = NULL;
	init_stack(a, ac, av);
	check_sorted(a, b);
	if (a->size > 3)
		b = (t_stack *)malloc(sizeof(t_stack));
	sort_stack(a, b);
	free_stacks(a, b);
	return (0);
}
