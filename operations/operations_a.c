/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:15:05 by felperei          #+#    #+#             */
/*   Updated: 2024/02/07 09:16:13 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int sa(t_stack *stack_a)
{
     if (sa(stack_a) == -1)
        return -1;
    t_node *node1 = stack_a->head;
    t_node *node2 = node1->next;
    t_node *tmp = (t_node *)malloc(sizeof(t_node));
    if (!node1 || !node2)
        return;
    tmp->value = node1->value;
    node1->value = node2->value;
    node2->value = tmp->value;
    free(tmp);
    ft_printf("sa\n");
}



int pa(t_stack *stack_a, t_stack *stack_b)
{
         if (pa(stack_a) == -1)
        return -1;
    t_node *node_b = stack_b->head;
    stack_b->head = node_b->next;

    node_b->next = stack_a->head;
    stack_a->head = node_b;
    if (stack_a->size == 0)
        stack_a->tail = node_b;
    stack_a->size++;
    stack_b->size--;
    ft_printf("pa\n");
}

void ra(t_stack *stack_a)
{
    if (ra(stack_a) == -1)
        return -1;
    t_node *node_lst;
    t_node *node1;

    node1 = stack_a->head;
    node_lst = stack_a->tail;
    stack_a->head = node1->next;
    node1->next = NULL;
    node_lst->next = node1;
    stack_a->tail = node1;
    ft_printf("ra\n");
}

void rra(t_stack *stack_a)
{
    if (rra(stack_a) == -1)
        return -1;
    t_node *node_lst = stack_a->tail;
    t_node *node1 = stack_a->head;
    t_node *node_penultimate;
    while (node1 && node1->next && node1->next->next != NULL)
        node1 = node1->next;
    node_penultimate = node1;
    node1 = stack_a->head;
    node_lst->next = node1;
    node_penultimate->next = NULL;
    stack_a->head = node_lst;
    stack_a->tail = node_penultimate;
    ft_printf("rra\n");
}