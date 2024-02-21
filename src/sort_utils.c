/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:14:56 by feliperei         #+#    #+#             */
/*   Updated: 2024/02/21 14:20:01 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *list)
{
	t_node	*node;
	t_node	*tmp;

	if (list == NULL)
		return ;
	node = list->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(list);
}

int	is_sorted(t_stack *list)
{
	t_node	*node;

	node = list->head;
	while (node->next != NULL)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	check_little(int i, t_node *node, t_node *node_tail, t_stack *stack_a)
{
	if (i == node->value)
		return ;
	else if (i == node->next->value)
		sa(stack_a);
	else if (i == node_tail->value)
		rra(stack_a);
	else if (i == find_midle(stack_a))
		rra3(stack_a);
	else
	{
		rra(stack_a);
		rra(stack_a);
	}
}

void	little(t_stack *stack_a)
{
	t_node	*node;
	t_node	*node_tail;
	int		i;

	node = stack_a->head;
	node_tail = stack_a->tail;
	i = node->value;
	while (node->next)
	{
		if (node->next->value < i)
			i = node->next->value;
		node = node->next;
	}
	node = stack_a->head;
	check_little(i, node, node_tail, stack_a);
}

int	find_midle(t_stack *stack_a)
{
	t_node	*slow;
	t_node	*fast;
	int		i;

	i = 0;
	slow = stack_a->head;
	fast = stack_a->head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	i = slow->value;
	return (i);
}
