/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:53:55 by felperei          #+#    #+#             */
/*   Updated: 2024/02/21 14:31:23 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->size < 2) || (stack_b->size < 2))
		return (-1);
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	return (0);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->size < 2) || (stack_b->size < 2))
		return (-1);
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
	return (0);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->size < 2) || (stack_b->size < 2))
		return (-1);
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
	return (0);
}
