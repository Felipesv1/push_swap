/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliperei <feliperei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:48:14 by felperei          #+#    #+#             */
/*   Updated: 2024/02/19 12:50:28 by feliperei        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int sb(t_stack *stack_b)
{
   	if (stack_b->size < 2)
		return (-1);
    t_node *node1 = stack_b->head;
    t_node *node2 = node1->next;
    t_node *tmp = (t_node *)malloc(sizeof(t_node));
    if (!node1 || !node2)
        return -1;
    tmp->value = node1->value;
    node1->value = node2->value;
    node2->value = tmp->value;
    free(tmp);
    ft_printf("sb\n");
    return (0);
}
int pb(t_stack *stack_b, t_stack *stack_a)
{
   
    if (stack_a->size == 0)
        return -1; 

    t_node *tmp = stack_a->head;
    stack_a->head = stack_a->head->next;
    stack_a->size--;

    tmp->next = stack_b->head;
    stack_b->head = tmp;
    stack_b->size++;

    if (stack_b->size == 1)
        stack_b->tail = stack_b->head;

    ft_printf("pb\n");

    return 0;
}

int rb(t_stack *stack_b)
{
 	if (stack_b->size < 2 || stack_b->head == NULL)
		return (-1);
    t_node *node_lst;
    t_node *node1;

    node1 = stack_b->head;
    node_lst = stack_b->tail;
    stack_b->head = node1->next;
    node1->next = NULL;
    node_lst->next = node1;
    stack_b->tail = node1;
    ft_printf("rb\n");
    return (0);
}
int rrb(t_stack *stack_b)
{
    	if (stack_b->size < 2)
		return (-1);
    t_node *node_lst = stack_b->tail;
    t_node *node1 = stack_b->head;
    t_node *node_penultimate;

    while (node1 && node1->next->next != NULL)
        node1 = node1->next;
    node_penultimate = node1;
    node1 = stack_b->head;
    node_lst->next = node1;
    node_penultimate->next = NULL;
    stack_b->head = node_lst;
    ft_printf("rrb\n");
    return (0);

}