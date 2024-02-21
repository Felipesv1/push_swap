/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:15:05 by felperei          #+#    #+#             */
/*   Updated: 2024/02/21 11:20:48 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stack *stack_a)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*tmp;

	if (stack_a->size < 2)
		return (-1);
	node1 = stack_a->head;
	node2 = node1->next;
	tmp = (t_node *)malloc(sizeof(t_node));
	if (!node1 || !node2)
		return (-1);
	tmp->value = node1->value;
	node1->value = node2->value;
	node2->value = tmp->value;
	free(tmp);
	ft_printf("sa\n");
	return (0);
}

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_b->size == 0)
		return (-1);
	tmp = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->size--;
	tmp->next = stack_a->head;
	stack_a->head = tmp;
	stack_a->size++;
	if (stack_a->size == 1)
		stack_a->tail = stack_a->head;
	ft_printf("pa\n");
	return (0);
}

int	ra(t_stack *stack_a)
{
	t_node	*node_lst;
	t_node	*node1;

	if (stack_a->size < 2 || stack_a->head == NULL)
		return (-1);
	node1 = stack_a->head;
	node_lst = stack_a->tail;
	stack_a->head = node1->next;
	node1->next = NULL;
	node_lst->next = node1;
	stack_a->tail = node1;
	ft_printf("ra\n");
	return (0);
}

int	rra(t_stack *stack_a)
{
	t_node	*node_lst;
	t_node	*node1;
	t_node	*node_penultimate;

	if (stack_a->size < 2)
		return (-1);
	node_lst = stack_a->tail;
	node1 = stack_a->head;
	while (node1 && node1->next && node1->next->next != NULL)
		node1 = node1->next;
	node_penultimate = node1;
	node1 = stack_a->head;
	node_lst->next = node1;
	node_penultimate->next = NULL;
	stack_a->head = node_lst;
	stack_a->tail = node_penultimate;
	ft_printf("rra\n");
	return (0);
}
